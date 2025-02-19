## strconv - Internals


### Table Of Contents
<a href="#table-of-contents"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Toc -->
* [Description](#description)
* [Sources](#sources)
* [Dependencies](#dependencies)
* [In Memory DB](#in-memory-db)

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Toc -->

### Description
<a href="#description"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Description -->
for usage, see [strconv - A simple string utility](/txt/exe/strconv/README.md)

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Description -->

### Sources
<a href="#sources"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Sources -->
The source code license is GPL
The following source files are part of this tool:

|Source File|Comment|
|---|---|
|[cpp/gen/strconv_gen.cpp](/cpp/gen/strconv_gen.cpp)||
|[cpp/strconv/strconv.cpp](/cpp/strconv/strconv.cpp)||
|[include/gen/strconv_gen.h](/include/gen/strconv_gen.h)||
|[include/gen/strconv_gen.inl.h](/include/gen/strconv_gen.inl.h)||
|[include/strconv.h](/include/strconv.h)||

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Sources -->

### Dependencies
<a href="#dependencies"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Dependencies -->
The build target depends on the following libraries
|Target|Comment|
|---|---|
|[algo_lib](/txt/lib/algo_lib/README.md)|Support library for all executables|

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Dependencies -->

### In Memory DB
<a href="#in-memory-db"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Imdb -->
`strconv` generated code creates the tables below.
All allocations are done through global `strconv::_db` [strconv.FDb](#strconv-fdb) structure
|Ctype|Ssimfile|Create|Access|
|---|---|---|---|
|[strconv.FDb](#strconv-fdb)||FDb._db (Global)|

#### strconv.FDb - In-memory database for strconv
<a href="#strconv-fdb"></a>

#### strconv.FDb Fields
<a href="#strconv-fdb-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|strconv.FDb._db|[strconv.FDb](/txt/exe/strconv/internals.md#strconv-fdb)|[Global](/txt/exe/amc/reftypes.md#global)|||
|strconv.FDb.cmdline|[command.strconv](/txt/protocol/command/README.md#command-strconv)|[Val](/txt/exe/amc/reftypes.md#val)|||

#### Struct FDb
<a href="#struct-fdb"></a>
Generated by [amc](/txt/exe/amc/README.md) into [include/gen/strconv_gen.h](/include/gen/strconv_gen.h)
```
struct FDb { // strconv.FDb: In-memory database for strconv
    command::strconv   cmdline;   //
    strconv::trace     trace;     //
};
```

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Imdb -->

