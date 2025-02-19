//
// include/gen/lib_iconv_gen.inl.h
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
//#pragma endinclude

// --- lib_iconv.trace..Ctor
inline  lib_iconv::trace::trace() {
}

// --- lib_iconv.FDb..Uninit
inline void lib_iconv::FDb_Uninit() {
    lib_iconv::FDb &row = _db; (void)row;
}

// --- lib_iconv.FieldId.value.GetEnum
// Get value of field as enum type
inline lib_iconv_FieldIdEnum lib_iconv::value_GetEnum(const lib_iconv::FieldId& parent) {
    return lib_iconv_FieldIdEnum(parent.value);
}

// --- lib_iconv.FieldId.value.SetEnum
// Set value of field from enum type.
inline void lib_iconv::value_SetEnum(lib_iconv::FieldId& parent, lib_iconv_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- lib_iconv.FieldId.value.Cast
inline  lib_iconv::FieldId::operator lib_iconv_FieldIdEnum() const {
    return lib_iconv_FieldIdEnum((*this).value);
}

// --- lib_iconv.FieldId..Init
// Set all fields to initial values.
inline void lib_iconv::FieldId_Init(lib_iconv::FieldId& parent) {
    parent.value = i32(-1);
}

// --- lib_iconv.FieldId..Ctor
inline  lib_iconv::FieldId::FieldId() {
    lib_iconv::FieldId_Init(*this);
}

// --- lib_iconv.FieldId..FieldwiseCtor
inline  lib_iconv::FieldId::FieldId(i32 in_value)
    : value(in_value)
 {
}

// --- lib_iconv.FieldId..EnumCtor
inline  lib_iconv::FieldId::FieldId(lib_iconv_FieldIdEnum arg) {
    this->value = i32(arg);
}

// --- lib_iconv.Icd..Init
// Set all fields to initial values.
inline void lib_iconv::Icd_Init(lib_iconv::Icd& icd) {
    icd.icd = iconv_t(((iconv_t)-1));
}

// --- lib_iconv.Icd..Uninit
inline void lib_iconv::Icd_Uninit(lib_iconv::Icd& icd) {
    lib_iconv::Icd &row = icd; (void)row;
    icd_Cleanup(icd); // dmmeta.fcleanup:lib_iconv.Icd.icd
}

// --- lib_iconv.Icd..Ctor
inline  lib_iconv::Icd::Icd() {
    lib_iconv::Icd_Init(*this);
}

// --- lib_iconv.Icd..Dtor
inline  lib_iconv::Icd::~Icd() {
    lib_iconv::Icd_Uninit(*this);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_iconv::trace &row) {// cfmt:lib_iconv.trace.String
    lib_iconv::trace_Print(const_cast<lib_iconv::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_iconv::FieldId &row) {// cfmt:lib_iconv.FieldId.String
    lib_iconv::FieldId_Print(const_cast<lib_iconv::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_iconv::Icd &row) {// cfmt:lib_iconv.Icd.String
    lib_iconv::Icd_Print(const_cast<lib_iconv::Icd&>(row), str);
    return str;
}
