#!/usr/bin/env python3

#
#    Copyright (c) 2017 Nest Labs, Inc.
#    All rights reserved.
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
#

#
#    @file
#       Calls Key Export Protocol between nodes.
#

from __future__ import absolute_import
from __future__ import print_function
import itertools
import os
import unittest
import set_test_path

from happy.Utils import *
import happy.HappyNodeList
import WeaveStateLoad
import WeaveStateUnload
import WeaveKeyExport
import WeaveUtilities

class test_weave_key_export_01(unittest.TestCase):
    def setUp(self):
        self.tap = None

        if os.environ.get("WEAVE_SYSTEM_CONFIG_USE_LWIP") == "1":
            self.topology_file = os.path.dirname(os.path.realpath(__file__)) + \
                "/../../../topologies/standalone/three_nodes_on_tap_wifi_weave.json"
            self.tap = "wpan0"
        else:
            self.topology_file = os.path.dirname(os.path.realpath(__file__)) + \
                "/../../../topologies/standalone/three_nodes_on_wifi_weave.json"

        self.show_strace = False

        # setting Mesh for thread test
        options = WeaveStateLoad.option()
        options["quiet"] = True
        options["json_file"] = self.topology_file

        setup_network = WeaveStateLoad.WeaveStateLoad(options)
        ret = setup_network.run()


    def tearDown(self):
        # cleaning up
        options = WeaveStateUnload.option()
        options["quiet"] = True
        options["json_file"] = self.topology_file

        teardown_network = WeaveStateUnload.WeaveStateUnload(options)
        teardown_network.run()


    def test_weave_key_export(self):
        # TODO: Once LwIP bugs are fix, enable this test on LwIP
        if os.environ.get("WEAVE_SYSTEM_CONFIG_USE_LWIP") == "1":
            return

        #                                                nodeA,    nodeB,    udp,  tcp,   wrmp,  key_id,    sign_msfs, test_tag
        print("Start Key Export over UDP")
        value, data = self.__run_key_export_test_between("node01", "node02", True, False, False, 0x00010400, True, "_KEY_EXPORT_UDP")
        self.__process_result("node01", "node02", value, data)

        print("Start Key Export over UDP + WRMP")
        value, data = self.__run_key_export_test_between("node01", "node02", True, False, True, 0x00010400, True, "_KEY_EXPORT_UDP_WRMP")
        self.__process_result("node01", "node02", value, data)

        print("Start Key Export over TCP")
        value, data = self.__run_key_export_test_between("node01", "node02", False, True, False, 0x00010400, True, "_KEY_EXPORT_TCP")
        self.__process_result("node01", "node02", value, data)

    def __process_result(self, nodeA, nodeB, value, data):
        print(" " + nodeA + " requested key export from " + nodeB + " ", end=' ')

        if value > 0:
            print(hred("Failed"))
        else:
            print(hgreen("Passed"))

        try:
            self.assertTrue(value == 0, "%s > 0 %%" % (str(value)))
        except AssertionError as e:
            print(str(e))
            print("Captured experiment result:")

            print("Client Output: ")
            for line in data["client_output"].split("\n"):
               print("\t" + line)

            print("Server Output: ")
            for line in data["server_output"].split("\n"):
                print("\t" + line)

            if self.show_strace == True:
                print("Server Strace: ")
                for line in data["server_strace"].split("\n"):
                    print("\t" + line)

                print("Client Strace: ")
                for line in data["client_strace"].split("\n"):
                    print("\t" + line)

        if value > 0:
            raise ValueError("Weave Key Export Failed")


    def __run_key_export_test_between(self, nodeA, nodeB, udp, tcp, wrmp, key_id, sign_msgs, test_tag):
        options = WeaveKeyExport.option()
        options["quiet"] = False
        options["client"] = nodeA
        options["server"] = nodeB
        options["udp"] = udp
        options["tcp"] = tcp
        options["wrmp"] = wrmp
        options["key_id"] = key_id
        options["sign_msgs"] = sign_msgs
        options["count"] = "1"
        options["tap"] = self.tap
        options["test_tag"] = test_tag

        weave_key_export = WeaveKeyExport.WeaveKeyExport(options)
        ret = weave_key_export.run()

        value = ret.Value()
        data = ret.Data()

        return value, data


if __name__ == "__main__":
    WeaveUtilities.run_unittest()


