/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "LuaWrapper.h"
#include <iostream>
#include "CProducer.h"

using namespace std;

static int testFunction(lua_State *L) {
    cout << "I am in test fuction." <<endl;
    return 0;
}

static const struct luaL_Reg rocketmqLuaLib[] = {
        {"testFunction", testFunction},
        {NULL, NULL}
};

int luaopen_librocketmqclientlua(lua_State *L) {
    const char* libName = "librocketmqclientlua";
    luaL_newlib(L,rocketmqLuaLib);
    lua_pushvalue(L,-1);
    lua_setglobal(L,libName);
    return 1;
}

