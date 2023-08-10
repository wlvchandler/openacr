//
// include/gen/fmdb_gen.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/algo_gen.h"
#include "include/gen/fm_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- fmdb_FieldIdEnum

enum fmdb_FieldIdEnum {                   // fmdb.FieldId.value
     fmdb_FieldId_alarm             = 0
    ,fmdb_FieldId_code              = 1
    ,fmdb_FieldId_object            = 2
    ,fmdb_FieldId_objtype           = 3
    ,fmdb_FieldId_objinst           = 4
    ,fmdb_FieldId_objprefix         = 5
    ,fmdb_FieldId_flag              = 6
    ,fmdb_FieldId_severity          = 7
    ,fmdb_FieldId_n_occurred        = 8
    ,fmdb_FieldId_first_time        = 9
    ,fmdb_FieldId_last_time         = 10
    ,fmdb_FieldId_clear_time        = 11
    ,fmdb_FieldId_update_time       = 12
    ,fmdb_FieldId_objtype_summary   = 13
    ,fmdb_FieldId_summary           = 14
    ,fmdb_FieldId_description       = 15
    ,fmdb_FieldId_source            = 16
    ,fmdb_FieldId_alm_code          = 17
    ,fmdb_FieldId_alm_objtype       = 18
    ,fmdb_FieldId_alm_source        = 19
    ,fmdb_FieldId_comment           = 20
    ,fmdb_FieldId_value             = 21
};

enum { fmdb_FieldIdEnum_N = 22 };

namespace fmdb { // gen:ns_pkeytypedef
    typedef algo::Smallstr200 AlarmPkey;
    typedef fm::Code AlmCodePkey;
    typedef fm::Objtype AlmObjtypePkey;
    typedef fm::Source AlmSourcePkey;
} // gen:ns_pkeytypedef
namespace fmdb { // gen:ns_field
} // gen:ns_field
// gen:ns_fwddecl2
namespace fmdb { struct Alarm; }
namespace fmdb { struct AlmCode; }
namespace fmdb { struct AlmObjtype; }
namespace fmdb { struct AlmSource; }
namespace fmdb { struct FieldId; }
namespace fmdb { // gen:ns_print_struct

// --- fmdb.Alarm
struct Alarm { // fmdb.Alarm
    algo::Smallstr200   alarm;             // Alarm identity: code@object
    fm::Flag            flag;              // Flag: raised or cleared
    fm::Severity        severity;          // Perceived severity
    i32                 n_occurred;        //   0  How many times the alarm occurred since first_time
    algo::UnTime        first_time;        // Time of first occurrence
    algo::UnTime        last_time;         // Time of last occurrence
    algo::UnTime        clear_time;        // Time when the alarm has beed cleared (only for cleared alarms
    algo::UnTime        update_time;       // Time of last update
    fm::Summary         objtype_summary;   // Object type explained
    fm::Summary         summary;           // Alarm summary from inventory
    fm::Description     description;       // Alarm message from object
    fm::Source          source;            // Subsystem where alarm has been detected
    Alarm();
};

fm::Code             code_Get(fmdb::Alarm& parent) __attribute__((__warn_unused_result__, nothrow));
fm::Code             Alarm_code_Get(algo::strptr arg) __attribute__((nothrow));

algo::Smallstr200    object_Get(fmdb::Alarm& parent) __attribute__((__warn_unused_result__, nothrow));
algo::Smallstr200    Alarm_object_Get(algo::strptr arg) __attribute__((nothrow));

fm::Objtype          objtype_Get(fmdb::Alarm& parent) __attribute__((__warn_unused_result__, nothrow));
fm::Objtype          Alarm_objtype_Get(algo::strptr arg) __attribute__((nothrow));

fm::Objinst          objinst_Get(fmdb::Alarm& parent) __attribute__((__warn_unused_result__, nothrow));
fm::Objinst          Alarm_objinst_Get(algo::strptr arg) __attribute__((nothrow));

algo::Smallstr50     objprefix_Get(fmdb::Alarm& parent) __attribute__((__warn_unused_result__, nothrow));
algo::Smallstr50     Alarm_objprefix_Get(algo::strptr arg) __attribute__((nothrow));

tempstr              Alarm_Concat_code_object( const algo::strptr& code ,const algo::strptr& object );
tempstr              Alarm_Concat_objtype_objinst( const algo::strptr& objtype ,const algo::strptr& objinst );
bool                 Alarm_ReadFieldMaybe(fmdb::Alarm &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of fmdb::Alarm from an ascii string.
// The format of the string is an ssim Tuple
bool                 Alarm_ReadStrptrMaybe(fmdb::Alarm &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 Alarm_Init(fmdb::Alarm& parent);
// print string representation of fmdb::Alarm to string LHS, no header -- cprint:fmdb.Alarm.String
void                 Alarm_Print(fmdb::Alarm & row, algo::cstring &str) __attribute__((nothrow));

// --- fmdb.AlmCode
struct AlmCode { // fmdb.AlmCode
    fm::Code       alm_code;   // Alarm code
    fm::Severity   severity;   // Assigned severity
    fm::Source     source;     //
    fm::Summary    summary;    // Alarm summary (slogan)
    AlmCode();
};

bool                 AlmCode_ReadFieldMaybe(fmdb::AlmCode &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of fmdb::AlmCode from an ascii string.
// The format of the string is an ssim Tuple
bool                 AlmCode_ReadStrptrMaybe(fmdb::AlmCode &parent, algo::strptr in_str);
// print string representation of fmdb::AlmCode to string LHS, no header -- cprint:fmdb.AlmCode.String
void                 AlmCode_Print(fmdb::AlmCode & row, algo::cstring &str) __attribute__((nothrow));

// --- fmdb.AlmObjtype
struct AlmObjtype { // fmdb.AlmObjtype: Alarm resource type
    fm::Objtype   alm_objtype;   // Object type
    fm::Summary   summary;       // Object type summary
    AlmObjtype();
};

bool                 AlmObjtype_ReadFieldMaybe(fmdb::AlmObjtype &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of fmdb::AlmObjtype from an ascii string.
// The format of the string is an ssim Tuple
bool                 AlmObjtype_ReadStrptrMaybe(fmdb::AlmObjtype &parent, algo::strptr in_str);
// print string representation of fmdb::AlmObjtype to string LHS, no header -- cprint:fmdb.AlmObjtype.String
void                 AlmObjtype_Print(fmdb::AlmObjtype & row, algo::cstring &str) __attribute__((nothrow));

// --- fmdb.AlmSource
struct AlmSource { // fmdb.AlmSource: Subsystem where alarm has been detected
    fm::Source      alm_source;   //
    algo::Comment   comment;      //
    AlmSource();
};

bool                 AlmSource_ReadFieldMaybe(fmdb::AlmSource &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of fmdb::AlmSource from an ascii string.
// The format of the string is an ssim Tuple
bool                 AlmSource_ReadStrptrMaybe(fmdb::AlmSource &parent, algo::strptr in_str);
// print string representation of fmdb::AlmSource to string LHS, no header -- cprint:fmdb.AlmSource.String
void                 AlmSource_Print(fmdb::AlmSource & row, algo::cstring &str) __attribute__((nothrow));

// --- fmdb.FieldId
#pragma pack(push,1)
struct FieldId { // fmdb.FieldId: Field read helper
    i32   value;   //   -1
    inline operator fmdb_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(fmdb_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
fmdb_FieldIdEnum     value_GetEnum(const fmdb::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(fmdb::FieldId& parent, fmdb_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const fmdb::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const fmdb::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(fmdb::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(fmdb::FieldId& parent, algo::strptr rhs, fmdb_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(fmdb::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of fmdb::FieldId from an ascii string.
// The format of the string is the format of the fmdb::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(fmdb::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(fmdb::FieldId& parent);
// print string representation of fmdb::FieldId to string LHS, no header -- cprint:fmdb.FieldId.String
void                 FieldId_Print(fmdb::FieldId & row, algo::cstring &str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace fmdb { // gen:ns_func
} // gen:ns_func
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const fmdb::Alarm &row);// cfmt:fmdb.Alarm.String
inline algo::cstring &operator <<(algo::cstring &str, const fmdb::AlmCode &row);// cfmt:fmdb.AlmCode.String
inline algo::cstring &operator <<(algo::cstring &str, const fmdb::AlmObjtype &row);// cfmt:fmdb.AlmObjtype.String
inline algo::cstring &operator <<(algo::cstring &str, const fmdb::AlmSource &row);// cfmt:fmdb.AlmSource.String
inline algo::cstring &operator <<(algo::cstring &str, const fmdb::FieldId &row);// cfmt:fmdb.FieldId.String
}