// $Header: /usr/local/cvsrep/rdnzl-cpp/RDNZL/Property.h,v 1.14 2008/02/14 07:34:32 edi Exp $
//
// Copyright (c) 2004-2008, Dr. Edmund Weitz.  All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//
//   * Redistributions in binary form must reproduce the above
//     copyright notice, this list of conditions and the following
//     disclaimer in the documentation and/or other materials
//     provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR 'AS IS' AND ANY EXPRESSED
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include "InvocationResult.h"

public ref class Property {
 public:
  static void *getPropertyValue(Object ^o, Type ^t, const __wchar_t *propertyName, BindingFlags bindingAttr, int nargs, void *args[]);
  static void *setPropertyValue(Object ^o, Type ^t, const __wchar_t *propertyName, BindingFlags bindingAttr, int nargs, void *args[]);
  static void *getPropertyValueDirectly(void *propertyInfo, int nargs, void *args[], bool staticp);
  static void *setPropertyValueDirectly(void *propertyInfo, int nargs, void *args[], bool staticp);
 private:
  static void throwPropertyNotFoundError(Type ^type, const __wchar_t *propertyName, cli::array<Type^> ^argTypes, BindingFlags bindingAttr);
};

extern "C" {
  __declspec(dllexport) void *getInstancePropertyValue(const __wchar_t *propertyName, void *target, int nargs, void *args[]);
  __declspec(dllexport) void *setInstancePropertyValue(const __wchar_t *propertyName, void *target, int nargs, void *args[]);
  __declspec(dllexport) void *getStaticPropertyValue(const __wchar_t *propertyName, void *type, int nargs, void *args[]);
  __declspec(dllexport) void *setStaticPropertyValue(const __wchar_t *propertyName, void *type, int nargs, void *args[]);
  __declspec(dllexport) void *getInstancePropertyValueDirectly(void *propertyInfo, int nargs, void *args[]);
  __declspec(dllexport) void *getStaticPropertyValueDirectly(void *propertyInfo, int nargs, void *args[]);
  __declspec(dllexport) void *setInstancePropertyValueDirectly(void *propertyInfo, int nargs, void *args[]);
  __declspec(dllexport) void *setStaticPropertyValueDirectly(void *propertyInfo, int nargs, void *args[]);
}
