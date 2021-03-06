//===-- SparcInstPrinter.h - Convert Sparc MCInst to assembly syntax ------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class prints an Sparc MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#ifndef SparcINSTPRINTER_H
#define SparcINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCSubtargetInfo.h"

namespace llvm {

class MCOperand;

class SparcInstPrinter : public MCInstPrinter {
  const MCSubtargetInfo &STI;
public:
 SparcInstPrinter(const MCAsmInfo &MAI,
                  const MCInstrInfo &MII,
                  const MCRegisterInfo &MRI,
                  const MCSubtargetInfo &sti)
   : MCInstPrinter(MAI, MII, MRI), STI(sti) {}

  virtual void printRegName(raw_ostream &OS, unsigned RegNo) const;
  virtual void printInst(const MCInst *MI, raw_ostream &O, StringRef Annot);
  bool printSparcAliasInstr(const MCInst *MI, raw_ostream &OS);
  bool isV9() const;

  // Autogenerated by tblgen.
  void printInstruction(const MCInst *MI, raw_ostream &O);
  bool printAliasInstr(const MCInst *MI, raw_ostream &O);
  static const char *getRegisterName(unsigned RegNo);

  void printOperand(const MCInst *MI, int opNum, raw_ostream &OS);
  void printMemOperand(const MCInst *MI, int opNum, raw_ostream &OS,
                       const char *Modifier = nullptr);
  void printCCOperand(const MCInst *MI, int opNum, raw_ostream &OS);
  bool printGetPCX(const MCInst *MI, unsigned OpNo, raw_ostream &OS);

};
} // end namespace llvm

#endif
