//===--- Scope.h - Scope Abstraction ----------------------------*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
//
// This file defines the Sema interface which implement hooks invoked by the 
// parser to build the AST.
//
//===----------------------------------------------------------------------===//

#ifndef SWIFT_SEMA_SCOPE_H
#define SWIFT_SEMA_SCOPE_H

#include "swift/AST/Identifier.h"
#include "llvm/ADT/ScopedHashTable.h"

namespace swift {
  class NamedDecl;
  class SemaDecl;
  
/// Scope - This class represents lexical scopes.  These objects are created
/// and destroyed as the parser is running, and name lookup happens relative
/// to them.
///
class Scope {
  Scope(const Scope&);          // DO NOT IMPLEMENT
  void operator=(const Scope&); // DO NOT IMPLEMENT
  
  SemaDecl &SD;
  
  typedef std::pair<unsigned, NamedDecl*> ScopeEntry;
  llvm::ScopedHashTableScope<Identifier, ScopeEntry> HTScope;
  Scope *PrevScope;
  unsigned Depth;
public:
  explicit Scope(SemaDecl &S);
  ~Scope();

  unsigned getDepth() const {
    return Depth;
  }
  
};
  
} // end namespace swift

#endif
