//
// include/gen/atf_ci_gen.inl.h
// Generated by AMC
//
// Copyright (C) 2008-2013 AlgoEngineering LLC
// Copyright (C) 2013-2019 NYSE | Intercontinental Exchange
// Copyright (C) 2020-2023 Astra
// Copyright (C) 2023 AlgoRND
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//


#pragma once
#include "include/gen/dev_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/atfdb_gen.inl.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/dmmeta_gen.inl.h"
//#pragma endinclude

// --- atf_ci.FBuilddir..Init
// Set all fields to initial values.
inline void atf_ci::FBuilddir_Init(atf_ci::FBuilddir& builddir) {
    builddir.ind_builddir_next = (atf_ci::FBuilddir*)-1; // (atf_ci.FDb.ind_builddir) not-in-hash
}

// --- atf_ci.FBuilddir..Ctor
inline  atf_ci::FBuilddir::FBuilddir() {
    atf_ci::FBuilddir_Init(*this);
}

// --- atf_ci.FBuilddir..Dtor
inline  atf_ci::FBuilddir::~FBuilddir() {
    atf_ci::FBuilddir_Uninit(*this);
}

// --- atf_ci.FCfg..Ctor
inline  atf_ci::FCfg::FCfg() {
}

// --- atf_ci.FCipackage..Init
// Set all fields to initial values.
inline void atf_ci::FCipackage_Init(atf_ci::FCipackage& cipackage) {
    cipackage.remove = bool(false);
    cipackage.build = bool(false);
}

// --- atf_ci.FCipackage..Ctor
inline  atf_ci::FCipackage::FCipackage() {
    atf_ci::FCipackage_Init(*this);
}

// --- atf_ci.FCitest.step.Call
// Invoke function by pointer
inline void atf_ci::step_Call(atf_ci::FCitest& citest) {
    if (citest.step) {
        citest.step();
    }
}

// --- atf_ci.FCitest..Init
// Set all fields to initial values.
inline void atf_ci::FCitest_Init(atf_ci::FCitest& citest) {
    citest.cijob = algo::strptr("test");
    citest.sandbox = bool(false);
    citest.nerr = i32(0);
    citest.step = NULL;
    citest.ind_citest_next = (atf_ci::FCitest*)-1; // (atf_ci.FDb.ind_citest) not-in-hash
}

// --- atf_ci.FCitest..Ctor
inline  atf_ci::FCitest::FCitest() {
    atf_ci::FCitest_Init(*this);
}

// --- atf_ci.FCitest..Dtor
inline  atf_ci::FCitest::~FCitest() {
    atf_ci::FCitest_Uninit(*this);
}

// --- atf_ci.trace..Ctor
inline  atf_ci::trace::trace() {
}

// --- atf_ci.FDb.citest.EmptyQ
// Return true if index is empty
inline bool atf_ci::citest_EmptyQ() {
    return _db.citest_n == 0;
}

// --- atf_ci.FDb.citest.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FCitest* atf_ci::citest_Find(u64 t) {
    atf_ci::FCitest *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.citest_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.citest_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.citest.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FCitest* atf_ci::citest_Last() {
    return citest_Find(u64(_db.citest_n-1));
}

// --- atf_ci.FDb.citest.N
// Return number of items in the pool
inline i32 atf_ci::citest_N() {
    return _db.citest_n;
}

// --- atf_ci.FDb.citest.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FCitest& atf_ci::citest_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.citest_lary[bsr][index];
}

// --- atf_ci.FDb.ssimfile.EmptyQ
// Return true if index is empty
inline bool atf_ci::ssimfile_EmptyQ() {
    return _db.ssimfile_n == 0;
}

// --- atf_ci.FDb.ssimfile.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FSsimfile* atf_ci::ssimfile_Find(u64 t) {
    atf_ci::FSsimfile *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.ssimfile_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.ssimfile_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.ssimfile.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FSsimfile* atf_ci::ssimfile_Last() {
    return ssimfile_Find(u64(_db.ssimfile_n-1));
}

// --- atf_ci.FDb.ssimfile.N
// Return number of items in the pool
inline i32 atf_ci::ssimfile_N() {
    return _db.ssimfile_n;
}

// --- atf_ci.FDb.ssimfile.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FSsimfile& atf_ci::ssimfile_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.ssimfile_lary[bsr][index];
}

// --- atf_ci.FDb.ind_ssimfile.EmptyQ
// Return true if hash is empty
inline bool atf_ci::ind_ssimfile_EmptyQ() {
    return _db.ind_ssimfile_n == 0;
}

// --- atf_ci.FDb.ind_ssimfile.N
// Return number of items in the hash
inline i32 atf_ci::ind_ssimfile_N() {
    return _db.ind_ssimfile_n;
}

// --- atf_ci.FDb.scriptfile.EmptyQ
// Return true if index is empty
inline bool atf_ci::scriptfile_EmptyQ() {
    return _db.scriptfile_n == 0;
}

// --- atf_ci.FDb.scriptfile.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FScriptfile* atf_ci::scriptfile_Find(u64 t) {
    atf_ci::FScriptfile *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.scriptfile_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.scriptfile_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.scriptfile.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FScriptfile* atf_ci::scriptfile_Last() {
    return scriptfile_Find(u64(_db.scriptfile_n-1));
}

// --- atf_ci.FDb.scriptfile.N
// Return number of items in the pool
inline i32 atf_ci::scriptfile_N() {
    return _db.scriptfile_n;
}

// --- atf_ci.FDb.scriptfile.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FScriptfile& atf_ci::scriptfile_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.scriptfile_lary[bsr][index];
}

// --- atf_ci.FDb.ind_scriptfile.EmptyQ
// Return true if hash is empty
inline bool atf_ci::ind_scriptfile_EmptyQ() {
    return _db.ind_scriptfile_n == 0;
}

// --- atf_ci.FDb.ind_scriptfile.N
// Return number of items in the hash
inline i32 atf_ci::ind_scriptfile_N() {
    return _db.ind_scriptfile_n;
}

// --- atf_ci.FDb.ns.EmptyQ
// Return true if index is empty
inline bool atf_ci::ns_EmptyQ() {
    return _db.ns_n == 0;
}

// --- atf_ci.FDb.ns.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FNs* atf_ci::ns_Find(u64 t) {
    atf_ci::FNs *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.ns_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.ns_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.ns.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FNs* atf_ci::ns_Last() {
    return ns_Find(u64(_db.ns_n-1));
}

// --- atf_ci.FDb.ns.N
// Return number of items in the pool
inline i32 atf_ci::ns_N() {
    return _db.ns_n;
}

// --- atf_ci.FDb.ns.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FNs& atf_ci::ns_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.ns_lary[bsr][index];
}

// --- atf_ci.FDb.ind_ns.EmptyQ
// Return true if hash is empty
inline bool atf_ci::ind_ns_EmptyQ() {
    return _db.ind_ns_n == 0;
}

// --- atf_ci.FDb.ind_ns.N
// Return number of items in the hash
inline i32 atf_ci::ind_ns_N() {
    return _db.ind_ns_n;
}

// --- atf_ci.FDb.readme.EmptyQ
// Return true if index is empty
inline bool atf_ci::readme_EmptyQ() {
    return _db.readme_n == 0;
}

// --- atf_ci.FDb.readme.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FReadme* atf_ci::readme_Find(u64 t) {
    atf_ci::FReadme *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.readme_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.readme_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.readme.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FReadme* atf_ci::readme_Last() {
    return readme_Find(u64(_db.readme_n-1));
}

// --- atf_ci.FDb.readme.N
// Return number of items in the pool
inline i32 atf_ci::readme_N() {
    return _db.readme_n;
}

// --- atf_ci.FDb.readme.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FReadme& atf_ci::readme_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.readme_lary[bsr][index];
}

// --- atf_ci.FDb.builddir.EmptyQ
// Return true if index is empty
inline bool atf_ci::builddir_EmptyQ() {
    return _db.builddir_n == 0;
}

// --- atf_ci.FDb.builddir.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FBuilddir* atf_ci::builddir_Find(u64 t) {
    atf_ci::FBuilddir *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.builddir_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.builddir_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.builddir.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FBuilddir* atf_ci::builddir_Last() {
    return builddir_Find(u64(_db.builddir_n-1));
}

// --- atf_ci.FDb.builddir.N
// Return number of items in the pool
inline i32 atf_ci::builddir_N() {
    return _db.builddir_n;
}

// --- atf_ci.FDb.builddir.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FBuilddir& atf_ci::builddir_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.builddir_lary[bsr][index];
}

// --- atf_ci.FDb.cfg.EmptyQ
// Return true if index is empty
inline bool atf_ci::cfg_EmptyQ() {
    return _db.cfg_n == 0;
}

// --- atf_ci.FDb.cfg.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FCfg* atf_ci::cfg_Find(u64 t) {
    atf_ci::FCfg *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.cfg_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.cfg_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.cfg.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FCfg* atf_ci::cfg_Last() {
    return cfg_Find(u64(_db.cfg_n-1));
}

// --- atf_ci.FDb.cfg.N
// Return number of items in the pool
inline i32 atf_ci::cfg_N() {
    return _db.cfg_n;
}

// --- atf_ci.FDb.cfg.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FCfg& atf_ci::cfg_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.cfg_lary[bsr][index];
}

// --- atf_ci.FDb.ind_builddir.EmptyQ
// Return true if hash is empty
inline bool atf_ci::ind_builddir_EmptyQ() {
    return _db.ind_builddir_n == 0;
}

// --- atf_ci.FDb.ind_builddir.N
// Return number of items in the hash
inline i32 atf_ci::ind_builddir_N() {
    return _db.ind_builddir_n;
}

// --- atf_ci.FDb.gitfile.EmptyQ
// Return true if index is empty
inline bool atf_ci::gitfile_EmptyQ() {
    return _db.gitfile_n == 0;
}

// --- atf_ci.FDb.gitfile.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FGitfile* atf_ci::gitfile_Find(u64 t) {
    atf_ci::FGitfile *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.gitfile_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.gitfile_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.gitfile.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FGitfile* atf_ci::gitfile_Last() {
    return gitfile_Find(u64(_db.gitfile_n-1));
}

// --- atf_ci.FDb.gitfile.N
// Return number of items in the pool
inline i32 atf_ci::gitfile_N() {
    return _db.gitfile_n;
}

// --- atf_ci.FDb.gitfile.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FGitfile& atf_ci::gitfile_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.gitfile_lary[bsr][index];
}

// --- atf_ci.FDb.ind_gitfile.EmptyQ
// Return true if hash is empty
inline bool atf_ci::ind_gitfile_EmptyQ() {
    return _db.ind_gitfile_n == 0;
}

// --- atf_ci.FDb.ind_gitfile.N
// Return number of items in the hash
inline i32 atf_ci::ind_gitfile_N() {
    return _db.ind_gitfile_n;
}

// --- atf_ci.FDb.noindent.EmptyQ
// Return true if index is empty
inline bool atf_ci::noindent_EmptyQ() {
    return _db.noindent_n == 0;
}

// --- atf_ci.FDb.noindent.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FNoindent* atf_ci::noindent_Find(u64 t) {
    atf_ci::FNoindent *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.noindent_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.noindent_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.noindent.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FNoindent* atf_ci::noindent_Last() {
    return noindent_Find(u64(_db.noindent_n-1));
}

// --- atf_ci.FDb.noindent.N
// Return number of items in the pool
inline i32 atf_ci::noindent_N() {
    return _db.noindent_n;
}

// --- atf_ci.FDb.noindent.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FNoindent& atf_ci::noindent_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.noindent_lary[bsr][index];
}

// --- atf_ci.FDb.targsrc.EmptyQ
// Return true if index is empty
inline bool atf_ci::targsrc_EmptyQ() {
    return _db.targsrc_n == 0;
}

// --- atf_ci.FDb.targsrc.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FTargsrc* atf_ci::targsrc_Find(u64 t) {
    atf_ci::FTargsrc *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.targsrc_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.targsrc_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.targsrc.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FTargsrc* atf_ci::targsrc_Last() {
    return targsrc_Find(u64(_db.targsrc_n-1));
}

// --- atf_ci.FDb.targsrc.N
// Return number of items in the pool
inline i32 atf_ci::targsrc_N() {
    return _db.targsrc_n;
}

// --- atf_ci.FDb.targsrc.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FTargsrc& atf_ci::targsrc_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.targsrc_lary[bsr][index];
}

// --- atf_ci.FDb.msgfile.EmptyQ
// Return true if index is empty
inline bool atf_ci::msgfile_EmptyQ() {
    return _db.msgfile_n == 0;
}

// --- atf_ci.FDb.msgfile.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FMsgfile* atf_ci::msgfile_Find(u64 t) {
    atf_ci::FMsgfile *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.msgfile_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.msgfile_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.msgfile.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FMsgfile* atf_ci::msgfile_Last() {
    return msgfile_Find(u64(_db.msgfile_n-1));
}

// --- atf_ci.FDb.msgfile.N
// Return number of items in the pool
inline i32 atf_ci::msgfile_N() {
    return _db.msgfile_n;
}

// --- atf_ci.FDb.msgfile.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FMsgfile& atf_ci::msgfile_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.msgfile_lary[bsr][index];
}

// --- atf_ci.FDb.ind_citest.EmptyQ
// Return true if hash is empty
inline bool atf_ci::ind_citest_EmptyQ() {
    return _db.ind_citest_n == 0;
}

// --- atf_ci.FDb.ind_citest.N
// Return number of items in the hash
inline i32 atf_ci::ind_citest_N() {
    return _db.ind_citest_n;
}

// --- atf_ci.FDb.file.EmptyQ
// Return true if index is empty
inline bool atf_ci::file_EmptyQ() {
    return _db.file_n == 0;
}

// --- atf_ci.FDb.file.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::File* atf_ci::file_Find(u64 t) {
    atf_ci::File *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.file_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.file_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.file.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::File* atf_ci::file_Last() {
    return file_Find(u64(_db.file_n-1));
}

// --- atf_ci.FDb.file.N
// Return number of items in the pool
inline i32 atf_ci::file_N() {
    return _db.file_n;
}

// --- atf_ci.FDb.file.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::File& atf_ci::file_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.file_lary[bsr][index];
}

// --- atf_ci.FDb.ind_file.EmptyQ
// Return true if hash is empty
inline bool atf_ci::ind_file_EmptyQ() {
    return _db.ind_file_n == 0;
}

// --- atf_ci.FDb.ind_file.N
// Return number of items in the hash
inline i32 atf_ci::ind_file_N() {
    return _db.ind_file_n;
}

// --- atf_ci.FDb.cipackage.EmptyQ
// Return true if index is empty
inline bool atf_ci::cipackage_EmptyQ() {
    return _db.cipackage_n == 0;
}

// --- atf_ci.FDb.cipackage.Find
// Look up row by row id. Return NULL if out of range
inline atf_ci::FCipackage* atf_ci::cipackage_Find(u64 t) {
    atf_ci::FCipackage *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.cipackage_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.cipackage_lary[bsr][index];
    }
    return retval;
}

// --- atf_ci.FDb.cipackage.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_ci::FCipackage* atf_ci::cipackage_Last() {
    return cipackage_Find(u64(_db.cipackage_n-1));
}

// --- atf_ci.FDb.cipackage.N
// Return number of items in the pool
inline i32 atf_ci::cipackage_N() {
    return _db.cipackage_n;
}

// --- atf_ci.FDb.cipackage.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_ci::FCipackage& atf_ci::cipackage_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.cipackage_lary[bsr][index];
}

// --- atf_ci.FDb.citest_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_citest_curs_Reset(_db_citest_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.citest_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_citest_curs_ValidQ(_db_citest_curs &curs) {
    return curs.index < _db.citest_n;
}

// --- atf_ci.FDb.citest_curs.Next
// proceed to next item
inline void atf_ci::_db_citest_curs_Next(_db_citest_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.citest_curs.Access
// item access
inline atf_ci::FCitest& atf_ci::_db_citest_curs_Access(_db_citest_curs &curs) {
    return citest_qFind(u64(curs.index));
}

// --- atf_ci.FDb.ssimfile_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_ssimfile_curs_Reset(_db_ssimfile_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.ssimfile_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_ssimfile_curs_ValidQ(_db_ssimfile_curs &curs) {
    return curs.index < _db.ssimfile_n;
}

// --- atf_ci.FDb.ssimfile_curs.Next
// proceed to next item
inline void atf_ci::_db_ssimfile_curs_Next(_db_ssimfile_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.ssimfile_curs.Access
// item access
inline atf_ci::FSsimfile& atf_ci::_db_ssimfile_curs_Access(_db_ssimfile_curs &curs) {
    return ssimfile_qFind(u64(curs.index));
}

// --- atf_ci.FDb.scriptfile_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_scriptfile_curs_Reset(_db_scriptfile_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.scriptfile_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_scriptfile_curs_ValidQ(_db_scriptfile_curs &curs) {
    return curs.index < _db.scriptfile_n;
}

// --- atf_ci.FDb.scriptfile_curs.Next
// proceed to next item
inline void atf_ci::_db_scriptfile_curs_Next(_db_scriptfile_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.scriptfile_curs.Access
// item access
inline atf_ci::FScriptfile& atf_ci::_db_scriptfile_curs_Access(_db_scriptfile_curs &curs) {
    return scriptfile_qFind(u64(curs.index));
}

// --- atf_ci.FDb.ns_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_ns_curs_Reset(_db_ns_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.ns_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_ns_curs_ValidQ(_db_ns_curs &curs) {
    return curs.index < _db.ns_n;
}

// --- atf_ci.FDb.ns_curs.Next
// proceed to next item
inline void atf_ci::_db_ns_curs_Next(_db_ns_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.ns_curs.Access
// item access
inline atf_ci::FNs& atf_ci::_db_ns_curs_Access(_db_ns_curs &curs) {
    return ns_qFind(u64(curs.index));
}

// --- atf_ci.FDb.readme_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_readme_curs_Reset(_db_readme_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.readme_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_readme_curs_ValidQ(_db_readme_curs &curs) {
    return curs.index < _db.readme_n;
}

// --- atf_ci.FDb.readme_curs.Next
// proceed to next item
inline void atf_ci::_db_readme_curs_Next(_db_readme_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.readme_curs.Access
// item access
inline atf_ci::FReadme& atf_ci::_db_readme_curs_Access(_db_readme_curs &curs) {
    return readme_qFind(u64(curs.index));
}

// --- atf_ci.FDb.builddir_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_builddir_curs_Reset(_db_builddir_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.builddir_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_builddir_curs_ValidQ(_db_builddir_curs &curs) {
    return curs.index < _db.builddir_n;
}

// --- atf_ci.FDb.builddir_curs.Next
// proceed to next item
inline void atf_ci::_db_builddir_curs_Next(_db_builddir_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.builddir_curs.Access
// item access
inline atf_ci::FBuilddir& atf_ci::_db_builddir_curs_Access(_db_builddir_curs &curs) {
    return builddir_qFind(u64(curs.index));
}

// --- atf_ci.FDb.cfg_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_cfg_curs_Reset(_db_cfg_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.cfg_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_cfg_curs_ValidQ(_db_cfg_curs &curs) {
    return curs.index < _db.cfg_n;
}

// --- atf_ci.FDb.cfg_curs.Next
// proceed to next item
inline void atf_ci::_db_cfg_curs_Next(_db_cfg_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.cfg_curs.Access
// item access
inline atf_ci::FCfg& atf_ci::_db_cfg_curs_Access(_db_cfg_curs &curs) {
    return cfg_qFind(u64(curs.index));
}

// --- atf_ci.FDb.gitfile_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_gitfile_curs_Reset(_db_gitfile_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.gitfile_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_gitfile_curs_ValidQ(_db_gitfile_curs &curs) {
    return curs.index < _db.gitfile_n;
}

// --- atf_ci.FDb.gitfile_curs.Next
// proceed to next item
inline void atf_ci::_db_gitfile_curs_Next(_db_gitfile_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.gitfile_curs.Access
// item access
inline atf_ci::FGitfile& atf_ci::_db_gitfile_curs_Access(_db_gitfile_curs &curs) {
    return gitfile_qFind(u64(curs.index));
}

// --- atf_ci.FDb.noindent_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_noindent_curs_Reset(_db_noindent_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.noindent_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_noindent_curs_ValidQ(_db_noindent_curs &curs) {
    return curs.index < _db.noindent_n;
}

// --- atf_ci.FDb.noindent_curs.Next
// proceed to next item
inline void atf_ci::_db_noindent_curs_Next(_db_noindent_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.noindent_curs.Access
// item access
inline atf_ci::FNoindent& atf_ci::_db_noindent_curs_Access(_db_noindent_curs &curs) {
    return noindent_qFind(u64(curs.index));
}

// --- atf_ci.FDb.targsrc_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_targsrc_curs_Reset(_db_targsrc_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.targsrc_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_targsrc_curs_ValidQ(_db_targsrc_curs &curs) {
    return curs.index < _db.targsrc_n;
}

// --- atf_ci.FDb.targsrc_curs.Next
// proceed to next item
inline void atf_ci::_db_targsrc_curs_Next(_db_targsrc_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.targsrc_curs.Access
// item access
inline atf_ci::FTargsrc& atf_ci::_db_targsrc_curs_Access(_db_targsrc_curs &curs) {
    return targsrc_qFind(u64(curs.index));
}

// --- atf_ci.FDb.msgfile_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_msgfile_curs_Reset(_db_msgfile_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.msgfile_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_msgfile_curs_ValidQ(_db_msgfile_curs &curs) {
    return curs.index < _db.msgfile_n;
}

// --- atf_ci.FDb.msgfile_curs.Next
// proceed to next item
inline void atf_ci::_db_msgfile_curs_Next(_db_msgfile_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.msgfile_curs.Access
// item access
inline atf_ci::FMsgfile& atf_ci::_db_msgfile_curs_Access(_db_msgfile_curs &curs) {
    return msgfile_qFind(u64(curs.index));
}

// --- atf_ci.FDb.file_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_file_curs_Reset(_db_file_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.file_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_file_curs_ValidQ(_db_file_curs &curs) {
    return curs.index < _db.file_n;
}

// --- atf_ci.FDb.file_curs.Next
// proceed to next item
inline void atf_ci::_db_file_curs_Next(_db_file_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.file_curs.Access
// item access
inline atf_ci::File& atf_ci::_db_file_curs_Access(_db_file_curs &curs) {
    return file_qFind(u64(curs.index));
}

// --- atf_ci.FDb.cipackage_curs.Reset
// cursor points to valid item
inline void atf_ci::_db_cipackage_curs_Reset(_db_cipackage_curs &curs, atf_ci::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_ci.FDb.cipackage_curs.ValidQ
// cursor points to valid item
inline bool atf_ci::_db_cipackage_curs_ValidQ(_db_cipackage_curs &curs) {
    return curs.index < _db.cipackage_n;
}

// --- atf_ci.FDb.cipackage_curs.Next
// proceed to next item
inline void atf_ci::_db_cipackage_curs_Next(_db_cipackage_curs &curs) {
    curs.index++;
}

// --- atf_ci.FDb.cipackage_curs.Access
// item access
inline atf_ci::FCipackage& atf_ci::_db_cipackage_curs_Access(_db_cipackage_curs &curs) {
    return cipackage_qFind(u64(curs.index));
}

// --- atf_ci.FExecLimit..Ctor
inline  atf_ci::FExecLimit::FExecLimit() {
}

// --- atf_ci.FGitfile.c_noindent.InsertMaybe
// Insert row into pointer index. Return final membership status.
inline bool atf_ci::c_noindent_InsertMaybe(atf_ci::FGitfile& gitfile, atf_ci::FNoindent& row) {
    atf_ci::FNoindent* ptr = gitfile.c_noindent;
    bool retval = (ptr == NULL) | (ptr == &row);
    if (retval) {
        gitfile.c_noindent = &row;
    }
    return retval;
}

// --- atf_ci.FGitfile.c_noindent.Remove
// Remove element from index. If element is not in index, do nothing.
inline void atf_ci::c_noindent_Remove(atf_ci::FGitfile& gitfile, atf_ci::FNoindent& row) {
    atf_ci::FNoindent *ptr = gitfile.c_noindent;
    if (LIKELY(ptr == &row)) {
        gitfile.c_noindent = NULL;
    }
}

// --- atf_ci.FGitfile.c_scriptfile.InsertMaybe
// Insert row into pointer index. Return final membership status.
inline bool atf_ci::c_scriptfile_InsertMaybe(atf_ci::FGitfile& gitfile, atf_ci::FScriptfile& row) {
    atf_ci::FScriptfile* ptr = gitfile.c_scriptfile;
    bool retval = (ptr == NULL) | (ptr == &row);
    if (retval) {
        gitfile.c_scriptfile = &row;
    }
    return retval;
}

// --- atf_ci.FGitfile.c_scriptfile.Remove
// Remove element from index. If element is not in index, do nothing.
inline void atf_ci::c_scriptfile_Remove(atf_ci::FGitfile& gitfile, atf_ci::FScriptfile& row) {
    atf_ci::FScriptfile *ptr = gitfile.c_scriptfile;
    if (LIKELY(ptr == &row)) {
        gitfile.c_scriptfile = NULL;
    }
}

// --- atf_ci.FGitfile.c_targsrc.InsertMaybe
// Insert row into pointer index. Return final membership status.
inline bool atf_ci::c_targsrc_InsertMaybe(atf_ci::FGitfile& gitfile, atf_ci::FTargsrc& row) {
    atf_ci::FTargsrc* ptr = gitfile.c_targsrc;
    bool retval = (ptr == NULL) | (ptr == &row);
    if (retval) {
        gitfile.c_targsrc = &row;
    }
    return retval;
}

// --- atf_ci.FGitfile.c_targsrc.Remove
// Remove element from index. If element is not in index, do nothing.
inline void atf_ci::c_targsrc_Remove(atf_ci::FGitfile& gitfile, atf_ci::FTargsrc& row) {
    atf_ci::FTargsrc *ptr = gitfile.c_targsrc;
    if (LIKELY(ptr == &row)) {
        gitfile.c_targsrc = NULL;
    }
}

// --- atf_ci.FGitfile..Init
// Set all fields to initial values.
inline void atf_ci::FGitfile_Init(atf_ci::FGitfile& gitfile) {
    gitfile.c_noindent = NULL;
    gitfile.c_scriptfile = NULL;
    gitfile.c_targsrc = NULL;
    gitfile.ind_gitfile_next = (atf_ci::FGitfile*)-1; // (atf_ci.FDb.ind_gitfile) not-in-hash
}

// --- atf_ci.FGitfile..Ctor
inline  atf_ci::FGitfile::FGitfile() {
    atf_ci::FGitfile_Init(*this);
}

// --- atf_ci.FGitfile..Dtor
inline  atf_ci::FGitfile::~FGitfile() {
    atf_ci::FGitfile_Uninit(*this);
}

// --- atf_ci.FMsgfile..Init
// Set all fields to initial values.
inline void atf_ci::FMsgfile_Init(atf_ci::FMsgfile& msgfile) {
    msgfile.strict = bool(false);
}

// --- atf_ci.FMsgfile..Ctor
inline  atf_ci::FMsgfile::FMsgfile() {
    atf_ci::FMsgfile_Init(*this);
}

// --- atf_ci.FNoindent..Ctor
inline  atf_ci::FNoindent::FNoindent() {
}

// --- atf_ci.FNoindent..Dtor
inline  atf_ci::FNoindent::~FNoindent() {
    atf_ci::FNoindent_Uninit(*this);
}

// --- atf_ci.FNs..Init
// Set all fields to initial values.
inline void atf_ci::FNs_Init(atf_ci::FNs& ns) {
    ns.ind_ns_next = (atf_ci::FNs*)-1; // (atf_ci.FDb.ind_ns) not-in-hash
}

// --- atf_ci.FNs..Ctor
inline  atf_ci::FNs::FNs() {
    atf_ci::FNs_Init(*this);
}

// --- atf_ci.FNs..Dtor
inline  atf_ci::FNs::~FNs() {
    atf_ci::FNs_Uninit(*this);
}

// --- atf_ci.FReadme..Init
// Set all fields to initial values.
inline void atf_ci::FReadme_Init(atf_ci::FReadme& readme) {
    readme.inl = bool(false);
    readme.sandbox = bool(false);
}

// --- atf_ci.FReadme..Ctor
inline  atf_ci::FReadme::FReadme() {
    atf_ci::FReadme_Init(*this);
}

// --- atf_ci.FScriptfile..Init
// Set all fields to initial values.
inline void atf_ci::FScriptfile_Init(atf_ci::FScriptfile& scriptfile) {
    scriptfile.ind_scriptfile_next = (atf_ci::FScriptfile*)-1; // (atf_ci.FDb.ind_scriptfile) not-in-hash
}

// --- atf_ci.FScriptfile..Ctor
inline  atf_ci::FScriptfile::FScriptfile() {
    atf_ci::FScriptfile_Init(*this);
}

// --- atf_ci.FScriptfile..Dtor
inline  atf_ci::FScriptfile::~FScriptfile() {
    atf_ci::FScriptfile_Uninit(*this);
}

// --- atf_ci.FSsimfile..Init
// Set all fields to initial values.
inline void atf_ci::FSsimfile_Init(atf_ci::FSsimfile& ssimfile) {
    ssimfile.ind_ssimfile_next = (atf_ci::FSsimfile*)-1; // (atf_ci.FDb.ind_ssimfile) not-in-hash
}

// --- atf_ci.FSsimfile..Ctor
inline  atf_ci::FSsimfile::FSsimfile() {
    atf_ci::FSsimfile_Init(*this);
}

// --- atf_ci.FSsimfile..Dtor
inline  atf_ci::FSsimfile::~FSsimfile() {
    atf_ci::FSsimfile_Uninit(*this);
}

// --- atf_ci.FTargsrc..Ctor
inline  atf_ci::FTargsrc::FTargsrc() {
}

// --- atf_ci.FTargsrc..Dtor
inline  atf_ci::FTargsrc::~FTargsrc() {
    atf_ci::FTargsrc_Uninit(*this);
}

// --- atf_ci.FieldId.value.GetEnum
// Get value of field as enum type
inline atf_ci_FieldIdEnum atf_ci::value_GetEnum(const atf_ci::FieldId& parent) {
    return atf_ci_FieldIdEnum(parent.value);
}

// --- atf_ci.FieldId.value.SetEnum
// Set value of field from enum type.
inline void atf_ci::value_SetEnum(atf_ci::FieldId& parent, atf_ci_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- atf_ci.FieldId.value.Cast
inline  atf_ci::FieldId::operator atf_ci_FieldIdEnum() const {
    return atf_ci_FieldIdEnum((*this).value);
}

// --- atf_ci.FieldId..Init
// Set all fields to initial values.
inline void atf_ci::FieldId_Init(atf_ci::FieldId& parent) {
    parent.value = i32(-1);
}

// --- atf_ci.FieldId..Ctor
inline  atf_ci::FieldId::FieldId() {
    atf_ci::FieldId_Init(*this);
}

// --- atf_ci.FieldId..FieldwiseCtor
inline  atf_ci::FieldId::FieldId(i32 in_value)
    : value(in_value)
 {
}

// --- atf_ci.FieldId..EnumCtor
inline  atf_ci::FieldId::FieldId(atf_ci_FieldIdEnum arg) {
    this->value = i32(arg);
}

// --- atf_ci.File..Init
// Set all fields to initial values.
inline void atf_ci::File_Init(atf_ci::File& file) {
    file.file_exists = bool(false);
    file.record_exists = bool(false);
    file.ind_file_next = (atf_ci::File*)-1; // (atf_ci.FDb.ind_file) not-in-hash
}

// --- atf_ci.File..Ctor
inline  atf_ci::File::File() {
    atf_ci::File_Init(*this);
}

// --- atf_ci.File..Dtor
inline  atf_ci::File::~File() {
    atf_ci::File_Uninit(*this);
}

// --- atf_ci.TableId.value.GetEnum
// Get value of field as enum type
inline atf_ci_TableIdEnum atf_ci::value_GetEnum(const atf_ci::TableId& parent) {
    return atf_ci_TableIdEnum(parent.value);
}

// --- atf_ci.TableId.value.SetEnum
// Set value of field from enum type.
inline void atf_ci::value_SetEnum(atf_ci::TableId& parent, atf_ci_TableIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- atf_ci.TableId.value.Cast
inline  atf_ci::TableId::operator atf_ci_TableIdEnum() const {
    return atf_ci_TableIdEnum((*this).value);
}

// --- atf_ci.TableId..Init
// Set all fields to initial values.
inline void atf_ci::TableId_Init(atf_ci::TableId& parent) {
    parent.value = i32(-1);
}

// --- atf_ci.TableId..Ctor
inline  atf_ci::TableId::TableId() {
    atf_ci::TableId_Init(*this);
}

// --- atf_ci.TableId..FieldwiseCtor
inline  atf_ci::TableId::TableId(i32 in_value)
    : value(in_value)
 {
}

// --- atf_ci.TableId..EnumCtor
inline  atf_ci::TableId::TableId(atf_ci_TableIdEnum arg) {
    this->value = i32(arg);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const atf_ci::trace &row) {// cfmt:atf_ci.trace.String
    atf_ci::trace_Print(const_cast<atf_ci::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const atf_ci::FieldId &row) {// cfmt:atf_ci.FieldId.String
    atf_ci::FieldId_Print(const_cast<atf_ci::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const atf_ci::TableId &row) {// cfmt:atf_ci.TableId.String
    atf_ci::TableId_Print(const_cast<atf_ci::TableId&>(row), str);
    return str;
}
