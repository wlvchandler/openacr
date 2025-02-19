//
// cpp/gen/lib_sqlite_gen.cpp
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


#include "include/algo.h"  // hard-coded include
#include "include/gen/lib_sqlite_gen.h"
#include "include/gen/lib_sqlite_gen.inl.h"
#include "include/gen/algo_gen.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/dmmeta_gen.h"
#include "include/gen/dmmeta_gen.inl.h"
#include "include/gen/lib_ctype_gen.h"
#include "include/gen/lib_ctype_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
#include "include/gen/lib_amcdb_gen.h"
#include "include/gen/lib_amcdb_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/lib_prot_gen.h"
#include "include/gen/lib_prot_gen.inl.h"
//#pragma endinclude
namespace lib_sqlite { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    // func:lib_sqlite.FDb._db.InitReflection
    static void          InitReflection();
    // func:lib_sqlite.FDb.substr.InputMaybe
    static bool          substr_InputMaybe(dmmeta::Substr &elem) __attribute__((nothrow));
    // find trace by row id (used to implement reflection)
    // func:lib_sqlite.FDb.trace.RowidFind
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    // func:lib_sqlite.FDb.trace.N
    inline static i32    trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    // func:lib_sqlite...SizeCheck
    inline static void   SizeCheck();
} // gen:ns_print_proto

// --- lib_sqlite.FConn..Uninit
void lib_sqlite::FConn_Uninit(lib_sqlite::FConn& conn) {
    lib_sqlite::FConn &row = conn; (void)row;
    ind_conn_Remove(row); // remove conn from index ind_conn
    db_Cleanup(conn); // dmmeta.fcleanup:lib_sqlite.FConn.db
}

// --- lib_sqlite.trace..Print
// print string representation of ROW to string STR
// cfmt:lib_sqlite.trace.String  printfmt:Tuple
void lib_sqlite::trace_Print(lib_sqlite::trace& row, algo::cstring& str) {
    algo::tempstr temp;
    str << "lib_sqlite.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- lib_sqlite.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void lib_sqlite::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("lib_sqlite", lib_sqlite::InsertStrptrMaybe, NULL, NULL, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "lib_sqlite.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(lib_sqlite::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)lib_sqlite::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
    algo_lib::InsertStrptrMaybe("dmmeta.Dispsigcheck  dispsig:'lib_sqlite.Input'  signature:'8875eb4f7a60879bd250a23448b236d752a4dbb5'");
}

// --- lib_sqlite.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool lib_sqlite::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    lib_sqlite::TableId table_id(-1);
    value_SetStrptrMaybe(table_id, algo::GetTypeTag(str));
    switch (value_GetEnum(table_id)) {
        case lib_sqlite_TableId_dmmeta_Substr: { // finput:lib_sqlite.FDb.substr
            dmmeta::Substr elem;
            retval = dmmeta::Substr_ReadStrptrMaybe(elem, str);
            retval = retval && substr_InputMaybe(elem);
            break;
        }
        default:
        break;
    } //switch
    if (!retval) {
        algo_lib::NoteInsertErr(str); // increment error counter
    }
    return retval;
}

// --- lib_sqlite.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool lib_sqlite::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = lib_sqlite::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = lib_sqlite::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.ctype"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.field"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.substr"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.ssimfile"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.sqltype"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.ftuple"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.fconst"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.cppfunc"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.cfmt"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dmmeta.cdflt"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"dev.unstablefld"),recursive);
        retval = retval && lib_sqlite::LoadTuplesFile(algo::SsimFname(root,"amcdb.bltin"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- lib_sqlite.FDb._db.LoadTuplesFile
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool lib_sqlite::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    // missing files are not an error
    fildes.fd = OpenRead(fname,algo::FileFlags());
    if (ValidQ(fildes.fd)) {
        retval = LoadTuplesFd(fildes.fd, fname, recursive);
    }
    return retval;
}

// --- lib_sqlite.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool lib_sqlite::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
    bool retval = true;
    ind_beg(algo::FileLine_curs,line,fd) {
        if (recursive) {
            retval = retval && algo_lib::InsertStrptrMaybe(line);
            retval = retval && lib_ctype::InsertStrptrMaybe(line);
        }
        retval = retval && lib_sqlite::InsertStrptrMaybe(line);
        if (!retval) {
            algo_lib::_db.errtext << eol
            << fname << ":"
            << (ind_curs(line).i+1)
            << ": " << line << eol;
            break;
        }
    }ind_end;
    return retval;
}

// --- lib_sqlite.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool lib_sqlite::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = lib_sqlite::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- lib_sqlite.FDb._db.Steps
// Calls Step function of dependencies
void lib_sqlite::Steps() {
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- lib_sqlite.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool lib_sqlite::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- lib_sqlite.FDb.conn.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
lib_sqlite::FConn& lib_sqlite::conn_Alloc() {
    lib_sqlite::FConn* row = conn_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("lib_sqlite.out_of_mem  field:lib_sqlite.FDb.conn  comment:'Alloc failed'");
    }
    return *row;
}

// --- lib_sqlite.FDb.conn.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
lib_sqlite::FConn* lib_sqlite::conn_AllocMaybe() {
    lib_sqlite::FConn *row = (lib_sqlite::FConn*)conn_AllocMem();
    if (row) {
        new (row) lib_sqlite::FConn; // call constructor
    }
    return row;
}

// --- lib_sqlite.FDb.conn.Delete
// Remove row from all global and cross indices, then deallocate row
void lib_sqlite::conn_Delete(lib_sqlite::FConn &row) {
    row.~FConn();
    conn_FreeMem(row);
}

// --- lib_sqlite.FDb.conn.AllocMem
// Allocate space for one element
// If no memory available, return NULL.
void* lib_sqlite::conn_AllocMem() {
    lib_sqlite::FConn *row = _db.conn_free;
    if (UNLIKELY(!row)) {
        conn_Reserve(1);
        row = _db.conn_free;
    }
    if (row) {
        _db.conn_free = row->conn_next;
    }
    return row;
}

// --- lib_sqlite.FDb.conn.FreeMem
// Remove mem from all global and cross indices, then deallocate mem
void lib_sqlite::conn_FreeMem(lib_sqlite::FConn &row) {
    if (UNLIKELY(row.conn_next != (lib_sqlite::FConn*)-1)) {
        FatalErrorExit("lib_sqlite.tpool_double_delete  pool:lib_sqlite.FDb.conn  comment:'double deletion caught'");
    }
    row.conn_next = _db.conn_free; // insert into free list
    _db.conn_free  = &row;
}

// --- lib_sqlite.FDb.conn.Reserve
// Preallocate memory for N more elements
// Return number of elements actually reserved.
u64 lib_sqlite::conn_Reserve(u64 n_elems) {
    u64 ret = 0;
    while (ret < n_elems) {
        u64 size = _db.conn_blocksize; // underlying allocator is probably Lpool
        u64 reserved = conn_ReserveMem(size);
        ret += reserved;
        if (reserved == 0) {
            break;
        }
    }
    return ret;
}

// --- lib_sqlite.FDb.conn.ReserveMem
// Allocate block of given size, break up into small elements and append to free list.
// Return number of elements reserved.
u64 lib_sqlite::conn_ReserveMem(u64 size) {
    u64 ret = 0;
    if (size >= sizeof(lib_sqlite::FConn)) {
        lib_sqlite::FConn *mem = (lib_sqlite::FConn*)algo_lib::malloc_AllocMem(size);
        ret = mem ? size / sizeof(lib_sqlite::FConn) : 0;
        // add newly allocated elements to the free list;
        for (u64 i=0; i < ret; i++) {
            mem[i].conn_next = _db.conn_free;
            _db.conn_free = mem+i;
        }
    }
    return ret;
}

// --- lib_sqlite.FDb.conn.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool lib_sqlite::conn_XrefMaybe(lib_sqlite::FConn &row) {
    bool retval = true;
    (void)row;
    // insert conn into index ind_conn
    if (true) { // user-defined insert condition
        bool success = ind_conn_InsertMaybe(row);
        if (UNLIKELY(!success)) {
            ch_RemoveAll(algo_lib::_db.errtext);
            algo_lib::_db.errtext << "lib_sqlite.duplicate_key  xref:lib_sqlite.FDb.ind_conn"; // check for duplicate key
            return false;
        }
    }
    return retval;
}

// --- lib_sqlite.FDb.ind_conn.Find
// Find row by key. Return NULL if not found.
lib_sqlite::FConn* lib_sqlite::ind_conn_Find(const algo::strptr& key) {
    u32 index = algo::cstring_Hash(0, key) & (_db.ind_conn_buckets_n - 1);
    lib_sqlite::FConn* *e = &_db.ind_conn_buckets_elems[index];
    lib_sqlite::FConn* ret=NULL;
    do {
        ret       = *e;
        bool done = !ret || (*ret).name == key;
        if (done) break;
        e         = &ret->ind_conn_next;
    } while (true);
    return ret;
}

// --- lib_sqlite.FDb.ind_conn.FindX
// Look up row by key and return reference. Throw exception if not found
lib_sqlite::FConn& lib_sqlite::ind_conn_FindX(const algo::strptr& key) {
    lib_sqlite::FConn* ret = ind_conn_Find(key);
    vrfy(ret, tempstr() << "lib_sqlite.key_error  table:ind_conn  key:'"<<key<<"'  comment:'key not found'");
    return *ret;
}

// --- lib_sqlite.FDb.ind_conn.GetOrCreate
// Find row by key. If not found, create and x-reference a new row with with this key.
lib_sqlite::FConn& lib_sqlite::ind_conn_GetOrCreate(const algo::strptr& key) {
    lib_sqlite::FConn* ret = ind_conn_Find(key);
    if (!ret) { //  if memory alloc fails, process dies; if insert fails, function returns NULL.
        ret         = &conn_Alloc();
        (*ret).name = key;
        bool good = conn_XrefMaybe(*ret);
        if (!good) {
            conn_Delete(*ret); // delete offending row, any existin xrefs are cleared
            ret = NULL;
        }
    }
    vrfy(ret, tempstr() << "lib_sqlite.create_error  table:ind_conn  key:'"<<key<<"'  comment:'bad xref'");
    return *ret;
}

// --- lib_sqlite.FDb.ind_conn.InsertMaybe
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool lib_sqlite::ind_conn_InsertMaybe(lib_sqlite::FConn& row) {
    ind_conn_Reserve(1);
    bool retval = true; // if already in hash, InsertMaybe returns true
    if (LIKELY(row.ind_conn_next == (lib_sqlite::FConn*)-1)) {// check if in hash already
        u32 index = algo::cstring_Hash(0, row.name) & (_db.ind_conn_buckets_n - 1);
        lib_sqlite::FConn* *prev = &_db.ind_conn_buckets_elems[index];
        do {
            lib_sqlite::FConn* ret = *prev;
            if (!ret) { // exit condition 1: reached the end of the list
                break;
            }
            if ((*ret).name == row.name) { // exit condition 2: found matching key
                retval = false;
                break;
            }
            prev = &ret->ind_conn_next;
        } while (true);
        if (retval) {
            row.ind_conn_next = *prev;
            _db.ind_conn_n++;
            *prev = &row;
        }
    }
    return retval;
}

// --- lib_sqlite.FDb.ind_conn.Remove
// Remove reference to element from hash index. If element is not in hash, do nothing
void lib_sqlite::ind_conn_Remove(lib_sqlite::FConn& row) {
    if (LIKELY(row.ind_conn_next != (lib_sqlite::FConn*)-1)) {// check if in hash already
        u32 index = algo::cstring_Hash(0, row.name) & (_db.ind_conn_buckets_n - 1);
        lib_sqlite::FConn* *prev = &_db.ind_conn_buckets_elems[index]; // addr of pointer to current element
        while (lib_sqlite::FConn *next = *prev) {                          // scan the collision chain for our element
            if (next == &row) {        // found it?
                *prev = next->ind_conn_next; // unlink (singly linked list)
                _db.ind_conn_n--;
                row.ind_conn_next = (lib_sqlite::FConn*)-1;// not-in-hash
                break;
            }
            prev = &next->ind_conn_next;
        }
    }
}

// --- lib_sqlite.FDb.ind_conn.Reserve
// Reserve enough room in the hash for N more elements. Return success code.
void lib_sqlite::ind_conn_Reserve(int n) {
    u32 old_nbuckets = _db.ind_conn_buckets_n;
    u32 new_nelems   = _db.ind_conn_n + n;
    // # of elements has to be roughly equal to the number of buckets
    if (new_nelems > old_nbuckets) {
        int new_nbuckets = i32_Max(algo::BumpToPow2(new_nelems), u32(4));
        u32 old_size = old_nbuckets * sizeof(lib_sqlite::FConn*);
        u32 new_size = new_nbuckets * sizeof(lib_sqlite::FConn*);
        // allocate new array. we don't use Realloc since copying is not needed and factor of 2 probably
        // means new memory will have to be allocated anyway
        lib_sqlite::FConn* *new_buckets = (lib_sqlite::FConn**)algo_lib::malloc_AllocMem(new_size);
        if (UNLIKELY(!new_buckets)) {
            FatalErrorExit("lib_sqlite.out_of_memory  field:lib_sqlite.FDb.ind_conn");
        }
        memset(new_buckets, 0, new_size); // clear pointers
        // rehash all entries
        for (int i = 0; i < _db.ind_conn_buckets_n; i++) {
            lib_sqlite::FConn* elem = _db.ind_conn_buckets_elems[i];
            while (elem) {
                lib_sqlite::FConn &row        = *elem;
                lib_sqlite::FConn* next       = row.ind_conn_next;
                u32 index          = algo::cstring_Hash(0, row.name) & (new_nbuckets-1);
                row.ind_conn_next     = new_buckets[index];
                new_buckets[index] = &row;
                elem               = next;
            }
        }
        // free old array
        algo_lib::malloc_FreeMem(_db.ind_conn_buckets_elems, old_size);
        _db.ind_conn_buckets_elems = new_buckets;
        _db.ind_conn_buckets_n = new_nbuckets;
    }
}

// --- lib_sqlite.FDb.substr.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
lib_sqlite::FSubstr& lib_sqlite::substr_Alloc() {
    lib_sqlite::FSubstr* row = substr_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("lib_sqlite.out_of_mem  field:lib_sqlite.FDb.substr  comment:'Alloc failed'");
    }
    return *row;
}

// --- lib_sqlite.FDb.substr.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
lib_sqlite::FSubstr* lib_sqlite::substr_AllocMaybe() {
    lib_sqlite::FSubstr *row = (lib_sqlite::FSubstr*)substr_AllocMem();
    if (row) {
        new (row) lib_sqlite::FSubstr; // call constructor
    }
    return row;
}

// --- lib_sqlite.FDb.substr.InsertMaybe
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
lib_sqlite::FSubstr* lib_sqlite::substr_InsertMaybe(const dmmeta::Substr &value) {
    lib_sqlite::FSubstr *row = &substr_Alloc(); // if out of memory, process dies. if input error, return NULL.
    substr_CopyIn(*row,const_cast<dmmeta::Substr&>(value));
    bool ok = substr_XrefMaybe(*row); // this may return false
    if (!ok) {
        substr_RemoveLast(); // delete offending row, any existing xrefs are cleared
        row = NULL; // forget this ever happened
    }
    return row;
}

// --- lib_sqlite.FDb.substr.AllocMem
// Allocate space for one element. If no memory available, return NULL.
void* lib_sqlite::substr_AllocMem() {
    u64 new_nelems     = _db.substr_n+1;
    // compute level and index on level
    u64 bsr   = algo::u64_BitScanReverse(new_nelems);
    u64 base  = u64(1)<<bsr;
    u64 index = new_nelems-base;
    void *ret = NULL;
    // if level doesn't exist yet, create it
    lib_sqlite::FSubstr*  lev   = NULL;
    if (bsr < 32) {
        lev = _db.substr_lary[bsr];
        if (!lev) {
            lev=(lib_sqlite::FSubstr*)algo_lib::malloc_AllocMem(sizeof(lib_sqlite::FSubstr) * (u64(1)<<bsr));
            _db.substr_lary[bsr] = lev;
        }
    }
    // allocate element from this level
    if (lev) {
        _db.substr_n = i32(new_nelems);
        ret = lev + index;
    }
    return ret;
}

// --- lib_sqlite.FDb.substr.RemoveAll
// Remove all elements from Lary
void lib_sqlite::substr_RemoveAll() {
    for (u64 n = _db.substr_n; n>0; ) {
        n--;
        substr_qFind(u64(n)).~FSubstr(); // destroy last element
        _db.substr_n = i32(n);
    }
}

// --- lib_sqlite.FDb.substr.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void lib_sqlite::substr_RemoveLast() {
    u64 n = _db.substr_n;
    if (n > 0) {
        n -= 1;
        substr_qFind(u64(n)).~FSubstr();
        _db.substr_n = i32(n);
    }
}

// --- lib_sqlite.FDb.substr.InputMaybe
static bool lib_sqlite::substr_InputMaybe(dmmeta::Substr &elem) {
    bool retval = true;
    retval = substr_InsertMaybe(elem) != nullptr;
    return retval;
}

// --- lib_sqlite.FDb.substr.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool lib_sqlite::substr_XrefMaybe(lib_sqlite::FSubstr &row) {
    bool retval = true;
    (void)row;
    return retval;
}

// --- lib_sqlite.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr lib_sqlite::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- lib_sqlite.FDb.trace.N
// Function return 1
inline static i32 lib_sqlite::trace_N() {
    return 1;
}

// --- lib_sqlite.FDb..Init
// Set all fields to initial values.
void lib_sqlite::FDb_Init() {
    // conn: initialize Tpool
    _db.conn_free      = NULL;
    _db.conn_blocksize = algo::BumpToPow2(64 * sizeof(lib_sqlite::FConn)); // allocate 64-127 elements at a time
    // initialize hash table for lib_sqlite::FConn;
    _db.ind_conn_n             	= 0; // (lib_sqlite.FDb.ind_conn)
    _db.ind_conn_buckets_n     	= 4; // (lib_sqlite.FDb.ind_conn)
    _db.ind_conn_buckets_elems 	= (lib_sqlite::FConn**)algo_lib::malloc_AllocMem(sizeof(lib_sqlite::FConn*)*_db.ind_conn_buckets_n); // initial buckets (lib_sqlite.FDb.ind_conn)
    if (!_db.ind_conn_buckets_elems) {
        FatalErrorExit("out of memory"); // (lib_sqlite.FDb.ind_conn)
    }
    memset(_db.ind_conn_buckets_elems, 0, sizeof(lib_sqlite::FConn*)*_db.ind_conn_buckets_n); // (lib_sqlite.FDb.ind_conn)
    // initialize LAry substr (lib_sqlite.FDb.substr)
    _db.substr_n = 0;
    memset(_db.substr_lary, 0, sizeof(_db.substr_lary)); // zero out all level pointers
    lib_sqlite::FSubstr* substr_first = (lib_sqlite::FSubstr*)algo_lib::malloc_AllocMem(sizeof(lib_sqlite::FSubstr) * (u64(1)<<4));
    if (!substr_first) {
        FatalErrorExit("out of memory");
    }
    for (int i = 0; i < 4; i++) {
        _db.substr_lary[i]  = substr_first;
        substr_first    += 1ULL<<i;
    }

    lib_sqlite::InitReflection();
}

// --- lib_sqlite.FDb..Uninit
void lib_sqlite::FDb_Uninit() {
    lib_sqlite::FDb &row = _db; (void)row;

    // lib_sqlite.FDb.substr.Uninit (Lary)  //
    // skip destruction in global scope

    // lib_sqlite.FDb.ind_conn.Uninit (Thash)  //
    // skip destruction of ind_conn in global scope
}

// --- lib_sqlite.FSubstr.base.CopyOut
// Copy fields out of row
void lib_sqlite::substr_CopyOut(lib_sqlite::FSubstr &row, dmmeta::Substr &out) {
    out.field = row.field;
    out.expr = row.expr;
    out.srcfield = row.srcfield;
}

// --- lib_sqlite.FSubstr.base.CopyIn
// Copy fields in to row
void lib_sqlite::substr_CopyIn(lib_sqlite::FSubstr &row, dmmeta::Substr &in) {
    row.field = in.field;
    row.expr = in.expr;
    row.srcfield = in.srcfield;
}

// --- lib_sqlite.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* lib_sqlite::value_ToCstr(const lib_sqlite::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case lib_sqlite_FieldId_value      : ret = "value";  break;
    }
    return ret;
}

// --- lib_sqlite.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void lib_sqlite::value_Print(const lib_sqlite::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- lib_sqlite.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool lib_sqlite::value_SetStrptrMaybe(lib_sqlite::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,lib_sqlite_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- lib_sqlite.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void lib_sqlite::value_SetStrptr(lib_sqlite::FieldId& parent, algo::strptr rhs, lib_sqlite_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- lib_sqlite.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool lib_sqlite::value_ReadStrptrMaybe(lib_sqlite::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- lib_sqlite.FieldId..ReadStrptrMaybe
// Read fields of lib_sqlite::FieldId from an ascii string.
// The format of the string is the format of the lib_sqlite::FieldId's only field
bool lib_sqlite::FieldId_ReadStrptrMaybe(lib_sqlite::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- lib_sqlite.FieldId..Print
// print string representation of ROW to string STR
// cfmt:lib_sqlite.FieldId.String  printfmt:Raw
void lib_sqlite::FieldId_Print(lib_sqlite::FieldId& row, algo::cstring& str) {
    lib_sqlite::value_Print(row, str);
}

// --- lib_sqlite.TableId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* lib_sqlite::value_ToCstr(const lib_sqlite::TableId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case lib_sqlite_TableId_dmmeta_Substr: ret = "dmmeta.Substr";  break;
    }
    return ret;
}

// --- lib_sqlite.TableId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void lib_sqlite::value_Print(const lib_sqlite::TableId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- lib_sqlite.TableId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool lib_sqlite::value_SetStrptrMaybe(lib_sqlite::TableId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 13: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('d','m','m','e','t','a','.','S'): {
                    if (memcmp(rhs.elems+8,"ubstr",5)==0) { value_SetEnum(parent,lib_sqlite_TableId_dmmeta_Substr); ret = true; break; }
                    break;
                }
                case LE_STR8('d','m','m','e','t','a','.','s'): {
                    if (memcmp(rhs.elems+8,"ubstr",5)==0) { value_SetEnum(parent,lib_sqlite_TableId_dmmeta_substr); ret = true; break; }
                    break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- lib_sqlite.TableId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void lib_sqlite::value_SetStrptr(lib_sqlite::TableId& parent, algo::strptr rhs, lib_sqlite_TableIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- lib_sqlite.TableId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool lib_sqlite::value_ReadStrptrMaybe(lib_sqlite::TableId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- lib_sqlite.TableId..ReadStrptrMaybe
// Read fields of lib_sqlite::TableId from an ascii string.
// The format of the string is the format of the lib_sqlite::TableId's only field
bool lib_sqlite::TableId_ReadStrptrMaybe(lib_sqlite::TableId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- lib_sqlite.TableId..Print
// print string representation of ROW to string STR
// cfmt:lib_sqlite.TableId.String  printfmt:Raw
void lib_sqlite::TableId_Print(lib_sqlite::TableId& row, algo::cstring& str) {
    lib_sqlite::value_Print(row, str);
}

// --- lib_sqlite...SizeCheck
inline static void lib_sqlite::SizeCheck() {
}

// --- lib_sqlite...StaticCheck
void lib_sqlite::StaticCheck() {
    algo_assert(_offset_of(lib_sqlite::FieldId, value) + sizeof(((lib_sqlite::FieldId*)0)->value) == sizeof(lib_sqlite::FieldId));
}
