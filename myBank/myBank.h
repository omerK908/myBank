#ifndef _MYBANK_H_
#define _MYBANK_H_
#define C_SIZE 50
#define R_SIZE 2
#define CLOSE 0
#define OPEN 1
extern double arr[][C_SIZE];

void O ();
void B ();
void D ();
void W ();
void C ();
void I ();
void P ();
void E ();

_Bool check (int i);
_Bool isOpen (int i);

#endif
