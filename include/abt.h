// Copyright (C) 2023-2024 AlgoRND
// Copyright (C) 2020-2021 Astra
// Copyright (C) 2017-2019 NYSE | Intercontinental Exchange
//
// License: GPL
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
// Contacting ICE: <https://www.theice.com/contact>
// Target: abt (exe) -- Algo Build Tool - build & link C++ targets
// Exceptions: NO
// Header: include/abt.h -- Main header
//

#include "include/algo.h"
#include "include/gen/abt_gen.h"
#include "include/gen/abt_gen.inl.h"

namespace abt { // update-hdr
    // Dear human:
    //     Text from here to the closing curly brace was produced by scanning
    //     source files. Editing this text is futile.
    //     To refresh the contents of this section, run 'update-hdr'.
    //     To convert this section to a hand-written section, remove the word 'update-hdr' from namespace line.

    // -------------------------------------------------------------------
    // cpp/abt/build.cpp -- Build dag execution
    //
    abt::FSyscmd* NewCmd(abt::FSyscmd *start, abt::FSyscmd *end);
    void Main_Build();

    // -------------------------------------------------------------------
    // cpp/abt/disas.cpp -- Disassemble
    //

    // Show disassembly of function matching regex _db.cmdline.disas
    // in all selected targets & build directories
    void Main_Disas();

    // -------------------------------------------------------------------
    // cpp/abt/main.cpp -- Algo Build Tool - Main file
    //
    bool HeaderExtQ(strptr ext);

    // Access cached 'stat' results for FNAME
    abt::FFilestat &GetFilestat(strptr fname);

    // how are we using this execkey???
    i64 execkey_Get(abt::FSyscmd &cmd);
    bool SourceQ(abt::FTargsrc &targsrc);

    // compute obj key by replacing path components
    // with .
    // So, cpp/abt/main.cpp becomes cpp.abt.main.cpp
    // Next step will be to replace the extension
    tempstr GetObjkey(strptr source);

    // Compute object pathname by combinindg builddir path,
    // objkey, and extension.
    tempstr GetObjpath(abt::FBuilddir &builddir, abt::FSrcfile &srcfile);
    void DeleteFileV(strptr path);
    tempstr GetOutfile(abt::FBuilddir &builddir, abt::FTarget &target);
    void Main();

    // -------------------------------------------------------------------
    // cpp/abt/ood.cpp
    //

    // Compute cumulative modification timestamp for source files
    // and targets.
    // This calculates SRCFILE.CUM_MODTIME, TARGET.CUM_MODTIME
    void ComputeTimestamps();

    // Recalculate SRCFILE.OOD, TARGET.OOD, TARGET.OUT_MODTIME
    // for given build directory BUILDDIR
    void ComputeOod(abt::FBuilddir &builddir);

    // -------------------------------------------------------------------
    // cpp/abt/opt.cpp -- Calculate compiler options
    //
    tempstr EvalSrcfileCmdline(abt::FBuilddir &builddir, abt::FTarget &target, abt::FSrcfile &srcfile);

    // Return list of object file pathnames and library pathnames for target TARGET
    // into output variables OBJS and LIBS
    void DepsObjList(abt::FBuilddir &builddir, abt::FTarget &target, cstring &objs, cstring &libs);
    tempstr EvalLinkCmdline(abt::FBuilddir &builddir, abt::FTarget &target);

    // -------------------------------------------------------------------
    // cpp/abt/scan.cpp
    //

    // This function always scans the entire graph of all sources
    void ScanSrcfile();
}
