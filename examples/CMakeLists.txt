 ##############################################################################
 #                                                                            #
 # Copyright 2019 Jan Henrik Weinstock                                        #
 #                                                                            #
 # Licensed under the Apache License, Version 2.0 (the "License");            #
 # you may not use this file except in compliance with the License.           #
 # You may obtain a copy of the License at                                    #
 #                                                                            #
 #     http://www.apache.org/licenses/LICENSE-2.0                             #
 #                                                                            #
 # Unless required by applicable law or agreed to in writing, software        #
 # distributed under the License is distributed on an "AS IS" BASIS,          #
 # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   #
 # See the License for the specific language governing permissions and        #
 # limitations under the License.                                             #
 #                                                                            #
 ##############################################################################

add_executable(fibonacci fibonacci.cpp)
target_link_libraries(fibonacci ftl)
install(TARGETS fibonacci DESTINATION examples)
install(FILES fibonacci.cpp DESTINATION examples)

add_executable(prime prime.cpp)
target_link_libraries(prime ftl)
install(TARGETS prime DESTINATION examples)
install(FILES prime.cpp DESTINATION examples)
