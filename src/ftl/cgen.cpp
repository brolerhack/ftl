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

#include "ftl/cgen.h"

namespace ftl {

    cgen::cgen(size_t size):
        m_cache(size),
        m_emitter(m_cache),
        m_alloc(m_emitter),
        m_exit(m_cache) {
        m_alloc.prologue();
        m_cache.align(16);
        m_exit.place();
        m_alloc.epilogue();
        m_cache.align(16);
    }

    cgen::~cgen() {
        // nothing to do
    }

    func cgen::gen_function() {
        return func(m_cache);
    }

    void cgen::gen_ret(value& val) {
        m_alloc.fetch(val, RAX);
        gen_jmp(m_exit, true);
    }

    void cgen::gen_jmp(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jmpi(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jo(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jo(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jno(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jno(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jb(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jb(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jae(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jae(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jz(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jz(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jnz(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jnz(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_je(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.je(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jne(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jne(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jbe(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jbe(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_ja(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.ja(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_js(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.js(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jns(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jns(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jp(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jp(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jnp(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jnp(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jl(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jl(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jge(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jge(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jle(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jle(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_jg(label& l, bool far) {
        fixup fix;
        i32 offset = far ? 128 : 0;
        m_emitter.jg(offset, &fix);
        l.add(fix);
    }

    void cgen::gen_add(value& dest, const value& src) {
        if (dest.is_mem() && src.is_mem())
            m_alloc.fetch(dest);
        m_emitter.addr(dest.bits, dest, src);
        dest.set_dirty();
    }

    void cgen::gen_or(value& dest, const value& src) {
        if (dest.is_mem() && src.is_mem())
            m_alloc.fetch(dest);
        m_emitter.orr(dest.bits, dest, src);
        dest.set_dirty();
    }

    void cgen::gen_adc(value& dest, const value& src) {
        if (dest.is_mem() && src.is_mem())
            m_alloc.fetch(dest);
        m_emitter.adcr(dest.bits, dest, src);
        dest.set_dirty();
    }

    void cgen::gen_sbb(value& dest, const value& src) {
        if (dest.is_mem() && src.is_mem())
            m_alloc.fetch(dest);
        m_emitter.sbbr(dest.bits, dest, src);
        dest.set_dirty();
    }

    void cgen::gen_and(value& dest, const value& src) {
        if (dest.is_mem() && src.is_mem())
            m_alloc.fetch(dest);
        m_emitter.andr(dest.bits, dest, src);
        dest.set_dirty();
    }

    void cgen::gen_sub(value& dest, const value& src) {
        if (dest.is_mem() && src.is_mem())
            m_alloc.fetch(dest);
        m_emitter.subr(dest.bits, dest, src);
        dest.set_dirty();
    }

    void cgen::gen_xor(value& dest, const value& src) {
        if (dest.is_mem() && src.is_mem())
            m_alloc.fetch(dest);
        m_emitter.addr(dest.bits, dest, src);
        dest.set_dirty();
    }

    void cgen::gen_cmp(value& dest, const value& src) {
        if (dest.is_mem() && src.is_mem())
            m_alloc.fetch(dest);
        m_emitter.cmpr(dest.bits, dest, src);
    }

    void cgen::gen_tst(value& dest, const value& src) {
        if (dest.is_mem() && src.is_mem())
            m_alloc.fetch(dest);
        m_emitter.tstr(dest.bits, dest, src);
    }

    void cgen::gen_add(value& dest, i32 val) {
        m_emitter.addi(dest.bits, dest, val);
        dest.set_dirty();
    }

    void cgen::gen_or(value& dest, i32 val) {
        m_emitter.ori(dest.bits, dest, val);
        dest.set_dirty();
    }

    void cgen::gen_adc(value& dest, i32 val) {
        m_emitter.adci(dest.bits, dest, val);
        dest.set_dirty();
    }

    void cgen::gen_sbb(value& dest, i32 val) {
        m_emitter.sbbi(dest.bits, dest, val);
        dest.set_dirty();
    }

    void cgen::gen_and(value& dest, i32 val) {
        m_emitter.andi(dest.bits, dest, val);
        dest.set_dirty();
    }

    void cgen::gen_sub(value& dest, i32 val) {
        m_emitter.subi(dest.bits, dest, val);
        dest.set_dirty();
    }

    void cgen::gen_xor(value& dest, i32 val) {
        m_emitter.xori(dest.bits, dest, val);
        dest.set_dirty();
    }

    void cgen::gen_cmp(value& dest, i32 val) {
        m_emitter.cmpi(dest.bits, dest, val);
        dest.set_dirty();
    }

    void cgen::gen_tst(value& dest, i32 val) {
        m_emitter.tsti(dest.bits, dest, val);
        dest.set_dirty();
    }

}