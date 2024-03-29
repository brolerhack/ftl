/******************************************************************************
 *                                                                            *
 * Copyright 2019 Jan Henrik Weinstock                                        *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License");            *
 * you may not use this file except in compliance with the License.           *
 * You may obtain a copy of the License at                                    *
 *                                                                            *
 *     http://www.apache.org/licenses/LICENSE-2.0                             *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 *                                                                            *
 ******************************************************************************/

#ifndef FTL_LABEL_H
#define FTL_LABEL_H

#include "ftl/common.h"
#include "ftl/bitops.h"
#include "ftl/error.h"

#include "ftl/fixup.h"
#include "ftl/cbuf.h"
#include "ftl/alloc.h"

namespace ftl {

    class label
    {
    private:
        u8* m_location;
        vector<fixup> m_fixups;
        cbuf& m_buffer;
        alloc& m_alloc;
        string m_name;

        void patch();

    public:
        const char* name() const { return m_name.c_str(); }

        bool is_placed() const { return m_location != NULL; }

        u8*  get_address() { return m_location; }
        const u8* get_address() const { return m_location; }

        label(const string& name, cbuf& buf, alloc& al, u8* location = NULL);
        label(label&& other);
        ~label();

        label() = delete;
        label(const label&) = delete;
        label& operator = (const label&) = delete;

        void add(const fixup& fix);
        void place(bool flush = true);
        void place(u8* location, bool flush);
    };

}

#endif
