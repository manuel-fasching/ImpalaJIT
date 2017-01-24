/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM x64 version 1.3.0
** DO NOT EDIT! The original file is in "compiler/assembly/assembly.dasc".
*/

#line 1 "compiler/assembly/assembly.dasc"
//
// Created by manuel on 06.11.16.
//

#include <assembly.hh>
#include <stack>
#include <stdio.h>


//|.arch x64
#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 11 "compiler/assembly/assembly.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 13 "compiler/assembly/assembly.dasc"
//|.globals lbl_
enum {
  lbl__MAX
};
#line 14 "compiler/assembly/assembly.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[904] = {
  85,72,137,229,72,137,232,72,131,232,16,255,221,4,37,237,255,221,24,72,131,
  232,8,255,102,15,19,69,252,248,221,69,252,248,255,102,15,19,77,252,248,221,
  69,252,248,255,102,15,19,85,252,248,221,69,252,248,255,102,15,19,93,252,248,
  221,69,252,248,255,102,15,19,101,252,248,221,69,252,248,255,102,15,19,109,
  252,248,221,69,252,248,255,102,15,19,117,252,248,221,69,252,248,255,102,15,
  19,125,252,248,221,69,252,248,255,221,133,233,255,248,1,255,248,2,255,248,
  3,255,248,4,255,248,5,255,248,6,255,248,7,255,248,8,255,248,9,255,252,233,
  244,247,255,252,233,244,248,255,252,233,244,249,255,252,233,244,250,255,252,
  233,244,251,255,252,233,244,252,255,252,233,244,253,255,252,233,244,254,255,
  252,233,244,255,255,252,233,244,1,255,252,233,244,2,255,252,233,244,3,255,
  252,233,244,4,255,252,233,244,5,255,252,233,244,6,255,252,233,244,7,255,252,
  233,244,8,255,252,233,244,9,255,15,133,244,247,255,15,132,244,247,255,15,
  134,244,247,255,15,131,244,247,255,15,130,244,247,255,15,135,244,247,255,
  15,133,244,248,255,15,132,244,248,255,15,134,244,248,255,15,131,244,248,255,
  15,130,244,248,255,15,135,244,248,255,15,133,244,249,255,15,132,244,249,255,
  15,134,244,249,255,15,131,244,249,255,15,130,244,249,255,15,135,244,249,255,
  15,133,244,250,255,15,132,244,250,255,15,134,244,250,255,15,131,244,250,255,
  15,130,244,250,255,15,135,244,250,255,15,133,244,251,255,15,132,244,251,255,
  15,134,244,251,255,15,131,244,251,255,15,130,244,251,255,15,135,244,251,255,
  15,133,244,252,255,15,132,244,252,255,15,134,244,252,255,15,131,244,252,255,
  15,130,244,252,255,15,135,244,252,255,15,133,244,253,255,15,132,244,253,255,
  15,134,244,253,255,15,131,244,253,255,15,130,244,253,255,15,135,244,253,255,
  15,133,244,254,255,15,132,244,254,255,15,134,244,254,255,15,131,244,254,255,
  15,130,244,254,255,15,135,244,254,255,15,133,244,255,255,15,132,244,255,255,
  15,134,244,255,255,15,131,244,255,255,15,130,244,255,255,15,135,244,255,255,
  15,141,244,247,255,15,141,244,248,255,15,141,244,249,255,15,141,244,250,255,
  15,141,244,251,255,15,141,244,252,255,15,141,244,253,255,15,141,244,254,255,
  15,141,244,255,255,15,133,244,1,255,15,132,244,1,255,15,134,244,1,255,15,
  131,244,1,255,15,130,244,1,255,15,135,244,1,255,15,133,244,2,255,15,132,244,
  2,255,15,134,244,2,255,15,131,244,2,255,15,130,244,2,255,15,135,244,2,255,
  15,133,244,3,255,15,132,244,3,255,15,134,244,3,255,15,131,244,3,255,15,130,
  244,3,255,15,135,244,3,255,15,133,244,4,255,15,132,244,4,255,15,134,244,4,
  255,15,131,244,4,255,15,130,244,4,255,15,135,244,4,255,15,133,244,5,255,15,
  132,244,5,255,15,134,244,5,255,15,131,244,5,255,15,130,244,5,255,15,135,244,
  5,255,15,133,244,6,255,15,132,244,6,255,15,134,244,6,255,15,131,244,6,255,
  15,130,244,6,255,15,135,244,6,255,15,133,244,7,255,15,132,244,7,255,15,134,
  244,7,255,15,131,244,7,255,15,130,244,7,255,15,135,244,7,255,15,133,244,8,
  255,15,132,244,8,255,15,134,244,8,255,15,131,244,8,255,15,130,244,8,255,15,
  135,244,8,255,15,133,244,9,255,15,132,244,9,255,15,134,244,9,255,15,131,244,
  9,255,15,130,244,9,255,15,135,244,9,255,15,141,244,1,255,15,141,244,2,255,
  15,141,244,3,255,15,141,244,4,255,15,141,244,5,255,15,141,244,6,255,15,141,
  244,7,255,15,141,244,8,255,15,141,244,9,255,222,193,255,222,252,233,255,222,
  201,255,222,252,249,255,217,224,255,217,252,250,255,223,252,241,221,216,255,
  221,93,252,248,102,15,18,69,252,248,255,93,195,255
};

#line 15 "compiler/assembly/assembly.dasc"

#include <sys/mman.h>

#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif


dasm_State* d;
void** labels;
int operator_;
int parameterCount;
dasm_State** Dst;


Assembly::~Assembly(){
}

void Assembly::initialize() {
    dasm_init(&d, DASM_MAXSECTION);

    labels = (void**) malloc(lbl__MAX);
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, impala_actions);

    Dst = &d;
}

void Assembly::prologue(){

    //| push rbp
    //| mov rbp, rsp
    //| mov rax, rbp
    //| sub rax, 16
    dasm_put(Dst, 0);
#line 50 "compiler/assembly/assembly.dasc"
}

void Assembly::pushConstantToFPUStack(double *value){
    //| fld qword [value]
    dasm_put(Dst, 12, value);
#line 54 "compiler/assembly/assembly.dasc"
}

void Assembly::storeLocalVariable() {
    //| fstp qword [rax]
    //| sub rax, 8
    dasm_put(Dst, 17);
#line 59 "compiler/assembly/assembly.dasc"
}

void Assembly::pushParameterToFPUStack(int index) {
    switch(index){
        case 0:
            {
                //| movlpd qword [rbp-8], xmm0
                //| fld qword [rbp-8]
                dasm_put(Dst, 24);
#line 67 "compiler/assembly/assembly.dasc"
                break;
            }
        case 1:
            {
                //| movlpd qword [rbp-8], xmm1
                //| fld qword [rbp-8]
                dasm_put(Dst, 35);
#line 73 "compiler/assembly/assembly.dasc"
                break;
            }
        case 2:
            {
                //| movlpd qword [rbp-8], xmm2
                //| fld qword [rbp-8]
                dasm_put(Dst, 46);
#line 79 "compiler/assembly/assembly.dasc"
                break;
            }
        case 3:
            {
                //| movlpd qword [rbp-8], xmm3
                //| fld qword [rbp-8]
                dasm_put(Dst, 57);
#line 85 "compiler/assembly/assembly.dasc"
                break;
            }
        case 4:
            {
                //| movlpd qword [rbp-8], xmm4
                //| fld qword [rbp-8]
                dasm_put(Dst, 68);
#line 91 "compiler/assembly/assembly.dasc"
                break;
            }
        case 5:
            {
                //| movlpd qword [rbp-8], xmm5
                //| fld qword [rbp-8]
                dasm_put(Dst, 79);
#line 97 "compiler/assembly/assembly.dasc"
                break;
            }
        case 6:
            {
                //| movlpd qword [rbp-8], xmm6
                //| fld qword [rbp-8]
                dasm_put(Dst, 90);
#line 103 "compiler/assembly/assembly.dasc"
                break;
            }
        case 7:
            {
                //| movlpd qword [rbp-8], xmm7
                //| fld qword [rbp-8]
                dasm_put(Dst, 101);
#line 109 "compiler/assembly/assembly.dasc"
                break;
            }
        default:
            {
                //| fld qword [rbp+(8+(index-7)*8)];
                dasm_put(Dst, 112, (8+(index-7)*8));
#line 114 "compiler/assembly/assembly.dasc"
            }
    }

}

void Assembly::pushLocalVariableToFPUStack(int index) {
// printf("Val: %u\n", index);
    //| fld qword [rbp-(16+index*8)];
    dasm_put(Dst, 112, -(16+index*8));
#line 122 "compiler/assembly/assembly.dasc"
}

void Assembly::addLocalLabel(int labelNumber) {
    switch(labelNumber) {
        case 1:
            {
                //| 1:
                dasm_put(Dst, 116);
#line 129 "compiler/assembly/assembly.dasc"
                // printf("1: \n");
                break;
            }
        case 2:
            {
                //| 2:
                dasm_put(Dst, 119);
#line 135 "compiler/assembly/assembly.dasc"
                // printf("2: \n");
                break;
            }
        case 3:
            {
                //| 3:
                dasm_put(Dst, 122);
#line 141 "compiler/assembly/assembly.dasc"
                // printf("3: \n");
                break;
            }
        case 4:
            {
                //| 4:
                dasm_put(Dst, 125);
#line 147 "compiler/assembly/assembly.dasc"
                // printf("4: \n");
                break;
            }
        case 5:
            {
                //| 5:
                dasm_put(Dst, 128);
#line 153 "compiler/assembly/assembly.dasc"
                // printf("5: \n");
                break;
            }
        case 6:
            {
                //| 6:
                dasm_put(Dst, 131);
#line 159 "compiler/assembly/assembly.dasc"
                // printf("6: \n");
                break;
            }
        case 7:
            {
                //| 7:
                dasm_put(Dst, 134);
#line 165 "compiler/assembly/assembly.dasc"
                // printf("7: \n");
                break;
            }
        case 8:
            {
                //| 8:
                dasm_put(Dst, 137);
#line 171 "compiler/assembly/assembly.dasc"
                // printf("8: \n");
                break;
            }
        case 9:
            {
                //| 9:
                dasm_put(Dst, 140);
#line 177 "compiler/assembly/assembly.dasc"
                // printf("9: \n");
                break;
            }
    }
}

void Assembly::jumpForwardTo(int labelNumber) {
    switch(labelNumber) {
            case 1:
                {
                    //| jmp >1
                    dasm_put(Dst, 143);
#line 188 "compiler/assembly/assembly.dasc"
                    // printf(">1 \n");
                    break;
                }
            case 2:
                {
                    //| jmp >2
                    dasm_put(Dst, 148);
#line 194 "compiler/assembly/assembly.dasc"
                    // printf(">2 \n");
                    break;
                }
            case 3:
                {
                    //| jmp >3
                    dasm_put(Dst, 153);
#line 200 "compiler/assembly/assembly.dasc"
                    // printf(">3 \n");
                    break;
                }
            case 4:
                {
                    //| jmp >4
                    dasm_put(Dst, 158);
#line 206 "compiler/assembly/assembly.dasc"
                    // printf(">4 \n");
                    break;
                }
            case 5:
                {
                    //| jmp >5
                    dasm_put(Dst, 163);
#line 212 "compiler/assembly/assembly.dasc"
                    // printf(">5 \n");
                    break;
                }
            case 6:
                {
                    //| jmp >6
                    dasm_put(Dst, 168);
#line 218 "compiler/assembly/assembly.dasc"
                    // printf(">6 \n");
                    break;
                }
            case 7:
                {
                    //| jmp >7
                    dasm_put(Dst, 173);
#line 224 "compiler/assembly/assembly.dasc"
                    // printf(">7 \n");
                    break;
                }
            case 8:
                {
                    //| jmp >8
                    dasm_put(Dst, 178);
#line 230 "compiler/assembly/assembly.dasc"
                    // printf(">8 \n");
                    break;
                }
            case 9:
                {
                    //| jmp >9
                    dasm_put(Dst, 183);
#line 236 "compiler/assembly/assembly.dasc"
                    // printf(">9 \n");
                    break;
                }
        }
}


void Assembly::jumpBackwardTo(int labelNumber) {
    switch(labelNumber) {
            case 1:
                {
                    //| jmp <1
                    dasm_put(Dst, 188);
#line 248 "compiler/assembly/assembly.dasc"
                    // printf("<1 \n");
                    break;
                }
            case 2:
                {
                    //| jmp <2
                    dasm_put(Dst, 193);
#line 254 "compiler/assembly/assembly.dasc"
                    // printf("<2 \n");
                    break;
                }
            case 3:
                {
                    //| jmp <3
                    dasm_put(Dst, 198);
#line 260 "compiler/assembly/assembly.dasc"
                    // printf("<3 \n");
                    break;
                }
            case 4:
                {
                    //| jmp <4
                    dasm_put(Dst, 203);
#line 266 "compiler/assembly/assembly.dasc"
                    // printf("<4 \n");
                    break;
                }
            case 5:
                {
                    //| jmp <5
                    dasm_put(Dst, 208);
#line 272 "compiler/assembly/assembly.dasc"
                    // printf("<5 \n");
                    break;
                }
            case 6:
                {
                    //| jmp <6
                    dasm_put(Dst, 213);
#line 278 "compiler/assembly/assembly.dasc"
                    // printf("<6 \n");
                    break;
                }
            case 7:
                {
                    //| jmp <7
                    dasm_put(Dst, 218);
#line 284 "compiler/assembly/assembly.dasc"
                    // printf("<7 \n");
                    break;
                }
            case 8:
                {
                    //| jmp <8
                    dasm_put(Dst, 223);
#line 290 "compiler/assembly/assembly.dasc"
                    // printf("<8 \n");
                    break;
                }
            case 9:
                {
                    //| jmp <9
                    dasm_put(Dst, 228);
#line 296 "compiler/assembly/assembly.dasc"
                    // printf("<9 \n");
                    break;
                }
        }
}


void Assembly::conditionalJumpForwardTo(int labelNumber, bool condition){
    if(condition == false){
        if(labelNumber == 1  && operator_==EQ)
            //| jne  >1
            dasm_put(Dst, 233);
#line 307 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
            //| je  >1
            dasm_put(Dst, 238);
#line 309 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
            //| jbe  >1
            dasm_put(Dst, 243);
#line 311 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
            //| jae  >1
            dasm_put(Dst, 248);
#line 313 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
            //| jb  >1
            dasm_put(Dst, 253);
#line 315 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
            //| ja  >1
            dasm_put(Dst, 258);
#line 317 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
            //| jne  >2
            dasm_put(Dst, 263);
#line 319 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
            //| je  >2
            dasm_put(Dst, 268);
#line 321 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
            //| jbe  >2
            dasm_put(Dst, 273);
#line 323 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
            //| jae  >2
            dasm_put(Dst, 278);
#line 325 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
            //| jb  >2
            dasm_put(Dst, 283);
#line 327 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
            //| ja  >2
            dasm_put(Dst, 288);
#line 329 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
            //| jne  >3
            dasm_put(Dst, 293);
#line 331 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
            //| je  >3
            dasm_put(Dst, 298);
#line 333 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
            //| jbe  >3
            dasm_put(Dst, 303);
#line 335 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
            //| jae  >3
            dasm_put(Dst, 308);
#line 337 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
            //| jb  >3
            dasm_put(Dst, 313);
#line 339 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
            //| ja  >3
            dasm_put(Dst, 318);
#line 341 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
            //| jne  >4
            dasm_put(Dst, 323);
#line 343 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
            //| je  >4
            dasm_put(Dst, 328);
#line 345 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
            //| jbe  >4
            dasm_put(Dst, 333);
#line 347 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
            //| jae  >4
            dasm_put(Dst, 338);
#line 349 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
            //| jb  >4
            dasm_put(Dst, 343);
#line 351 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
            //| ja  >4
            dasm_put(Dst, 348);
#line 353 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
            //| jne  >5
            dasm_put(Dst, 353);
#line 355 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
            //| je  >5
            dasm_put(Dst, 358);
#line 357 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
            //| jbe  >5
            dasm_put(Dst, 363);
#line 359 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
            //| jae  >5
            dasm_put(Dst, 368);
#line 361 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
            //| jb  >5
            dasm_put(Dst, 373);
#line 363 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
            //| ja  >5
            dasm_put(Dst, 378);
#line 365 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
            //| jne  >6
            dasm_put(Dst, 383);
#line 367 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
            //| je  >6
            dasm_put(Dst, 388);
#line 369 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
            //| jbe  >6
            dasm_put(Dst, 393);
#line 371 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
            //| jae  >6
            dasm_put(Dst, 398);
#line 373 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
            //| jb  >6
            dasm_put(Dst, 403);
#line 375 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
            //| ja  >6
            dasm_put(Dst, 408);
#line 377 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
            //| jne  >7
            dasm_put(Dst, 413);
#line 379 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
            //| je  >7
            dasm_put(Dst, 418);
#line 381 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
            //| jbe  >7
            dasm_put(Dst, 423);
#line 383 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
            //| jae  >7
            dasm_put(Dst, 428);
#line 385 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
            //| jb  >7
            dasm_put(Dst, 433);
#line 387 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
            //| ja  >7
            dasm_put(Dst, 438);
#line 389 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
            //| jne  >8
            dasm_put(Dst, 443);
#line 391 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
            //| je  >8
            dasm_put(Dst, 448);
#line 393 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
            //| jbe  >8
            dasm_put(Dst, 453);
#line 395 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
            //| jae  >8
            dasm_put(Dst, 458);
#line 397 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
            //| jb  >8
            dasm_put(Dst, 463);
#line 399 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
            //| ja  >8
            dasm_put(Dst, 468);
#line 401 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
            //| jne  >9
            dasm_put(Dst, 473);
#line 403 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
            //| je  >9
            dasm_put(Dst, 478);
#line 405 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
            //| jbe  >9
            dasm_put(Dst, 483);
#line 407 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
            //| jae  >9
            dasm_put(Dst, 488);
#line 409 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
            //| jb  >9
            dasm_put(Dst, 493);
#line 411 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
            //| ja  >9
            dasm_put(Dst, 498);
#line 413 "compiler/assembly/assembly.dasc"
    }
    else if(condition == true){
        if(labelNumber == 1  && operator_==EQ) 
            //| je  >1
            dasm_put(Dst, 238);
#line 417 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE) 
            //| jne  >1
            dasm_put(Dst, 233);
#line 419 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT) 
            //| ja  >1
            dasm_put(Dst, 258);
#line 421 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jb  >1
			 dasm_put(Dst, 253);
#line 423 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jge  >1
			 dasm_put(Dst, 503);
#line 425 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| jbe  >1
			 dasm_put(Dst, 243);
#line 427 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| je  >2
			 dasm_put(Dst, 268);
#line 429 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| jne  >2
			 dasm_put(Dst, 263);
#line 431 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| ja  >2
			 dasm_put(Dst, 288);
#line 433 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jb  >2
			 dasm_put(Dst, 283);
#line 435 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jge  >2
			 dasm_put(Dst, 508);
#line 437 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| jbe  >2
			 dasm_put(Dst, 273);
#line 439 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| je  >3
			 dasm_put(Dst, 298);
#line 441 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| jne  >3
			 dasm_put(Dst, 293);
#line 443 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| ja  >3
			 dasm_put(Dst, 318);
#line 445 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jb  >3
			 dasm_put(Dst, 313);
#line 447 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jge  >3
			 dasm_put(Dst, 513);
#line 449 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| jbe  >3
			 dasm_put(Dst, 303);
#line 451 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| je  >4
			 dasm_put(Dst, 328);
#line 453 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| jne  >4
			 dasm_put(Dst, 323);
#line 455 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| ja  >4
			 dasm_put(Dst, 348);
#line 457 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jb  >4
			 dasm_put(Dst, 343);
#line 459 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jge  >4
			 dasm_put(Dst, 518);
#line 461 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| jbe  >4
			 dasm_put(Dst, 333);
#line 463 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| je  >5
			 dasm_put(Dst, 358);
#line 465 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| jne  >5
			 dasm_put(Dst, 353);
#line 467 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| ja  >5
			 dasm_put(Dst, 378);
#line 469 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jb  >5
			 dasm_put(Dst, 373);
#line 471 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jge  >5
			 dasm_put(Dst, 523);
#line 473 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| jbe  >5
			 dasm_put(Dst, 363);
#line 475 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| je  >6
			 dasm_put(Dst, 388);
#line 477 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| jne  >6
			 dasm_put(Dst, 383);
#line 479 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| ja  >6
			 dasm_put(Dst, 408);
#line 481 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jb  >6
			 dasm_put(Dst, 403);
#line 483 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jge  >6
			 dasm_put(Dst, 528);
#line 485 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| jbe  >6
			 dasm_put(Dst, 393);
#line 487 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| je  >7
			 dasm_put(Dst, 418);
#line 489 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| jne  >7
			 dasm_put(Dst, 413);
#line 491 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| ja  >7
			 dasm_put(Dst, 438);
#line 493 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jb  >7
			 dasm_put(Dst, 433);
#line 495 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jge  >7
			 dasm_put(Dst, 533);
#line 497 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| jbe  >7
			 dasm_put(Dst, 423);
#line 499 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| je  >8
			 dasm_put(Dst, 448);
#line 501 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| jne  >8
			 dasm_put(Dst, 443);
#line 503 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| ja  >8
			 dasm_put(Dst, 468);
#line 505 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jb  >8
			 dasm_put(Dst, 463);
#line 507 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jge  >8
			 dasm_put(Dst, 538);
#line 509 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| jbe  >8
			 dasm_put(Dst, 453);
#line 511 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| je  >9
			 dasm_put(Dst, 478);
#line 513 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| jne  >9
			 dasm_put(Dst, 473);
#line 515 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| ja  >9
			 dasm_put(Dst, 498);
#line 517 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jb  >9
			 dasm_put(Dst, 493);
#line 519 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jge  >9
			 dasm_put(Dst, 543);
#line 521 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| jbe  >9
			 dasm_put(Dst, 483);
#line 523 "compiler/assembly/assembly.dasc"
        }
       /*
        if(condition == false){
                if(labelNumber == 1  && operator_==EQ) // printf("jne  >1\n");
                else if(labelNumber == 1 && operator_==NE) // printf("je  >1\n");
                else if(labelNumber == 1 && operator_==GT) // printf("jbe  >1\n");
                else if(labelNumber == 1 && operator_==LT) // printf("jae  >1\n");
                else if(labelNumber == 1 && operator_==GTE) // printf("jb  >1\n");
                else if(labelNumber == 1 && operator_==LTE) // printf("ja  >1\n");
                else if(labelNumber == 2  && operator_==EQ) // printf("jne  >2\n");
                else if(labelNumber == 2 && operator_==NE) // printf("je  >2\n");
                else if(labelNumber == 2 && operator_==GT) // printf("jbe  >2\n");
                else if(labelNumber == 2 && operator_==LT) // printf("jae  >2\n");
                else if(labelNumber == 2 && operator_==GTE) // printf("jb  >2\n");
                else if(labelNumber == 2 && operator_==LTE) // printf("ja  >2\n");
                else if(labelNumber == 3  && operator_==EQ) // printf("jne  >3\n");
                else if(labelNumber == 3 && operator_==NE) // printf("je  >3\n");
                else if(labelNumber == 3 && operator_==GT) // printf("jbe  >3\n");
                else if(labelNumber == 3 && operator_==LT) // printf("jae  >3\n");
                else if(labelNumber == 3 && operator_==GTE) // printf("jb  >3\n");
                else if(labelNumber == 3 && operator_==LTE) // printf("ja  >3\n");
                else if(labelNumber == 4  && operator_==EQ) // printf("jne  >4\n");
                else if(labelNumber == 4 && operator_==NE) // printf("je  >4\n");
                else if(labelNumber == 4 && operator_==GT) // printf("jbe  >4\n");
                else if(labelNumber == 4 && operator_==LT) // printf("jae  >4\n");
                else if(labelNumber == 4 && operator_==GTE) // printf("jb  >4\n");
                else if(labelNumber == 4 && operator_==LTE) // printf("ja  >4\n");
                else if(labelNumber == 5  && operator_==EQ) // printf("jne  >5\n");
                else if(labelNumber == 5 && operator_==NE) // printf("je  >5\n");
                else if(labelNumber == 5 && operator_==GT) // printf("jbe  >5\n");
                else if(labelNumber == 5 && operator_==LT) // printf("jae  >5\n");
                else if(labelNumber == 5 && operator_==GTE) // printf("jb  >5\n");
                else if(labelNumber == 5 && operator_==LTE) // printf("ja  >5\n");
                else if(labelNumber == 6  && operator_==EQ) // printf("jne  >6\n");
                else if(labelNumber == 6 && operator_==NE) // printf("je  >6\n");
                else if(labelNumber == 6 && operator_==GT) // printf("jbe  >6\n");
                else if(labelNumber == 6 && operator_==LT) // printf("jae  >6\n");
                else if(labelNumber == 6 && operator_==GTE) // printf("jb  >6\n");
                else if(labelNumber == 6 && operator_==LTE) // printf("ja  >6\n");
                else if(labelNumber == 7  && operator_==EQ) // printf("jne  >7\n");
                else if(labelNumber == 7 && operator_==NE) // printf("je  >7\n");
                else if(labelNumber == 7 && operator_==GT) // printf("jbe  >7\n");
                else if(labelNumber == 7 && operator_==LT) // printf("jae  >7\n");
                else if(labelNumber == 7 && operator_==GTE) // printf("jb  >7\n");
                else if(labelNumber == 7 && operator_==LTE) // printf("ja  >7\n");
                else if(labelNumber == 8  && operator_==EQ) // printf("jne  >8\n");
                else if(labelNumber == 8 && operator_==NE) // printf("je  >8\n");
                else if(labelNumber == 8 && operator_==GT) // printf("jbe  >8\n");
                else if(labelNumber == 8 && operator_==LT) // printf("jae  >8\n");
                else if(labelNumber == 8 && operator_==GTE) // printf("jb  >8\n");
                else if(labelNumber == 8 && operator_==LTE) // printf("ja  >8\n");
                else if(labelNumber == 9  && operator_==EQ) // printf("jne  >9\n");
                else if(labelNumber == 9 && operator_==NE) // printf("je  >9\n");
                else if(labelNumber == 9 && operator_==GT) // printf("jbe  >9\n");
                else if(labelNumber == 9 && operator_==LT) // printf("jae  >9\n");
                else if(labelNumber == 9 && operator_==GTE) // printf("jb  >9\n");
                else if(labelNumber == 9 && operator_==LTE) // printf("ja  >9\n");
            }else if(condition == true){
                if(labelNumber == 1  && operator_==EQ) // printf("je  >1\n");
                else if(labelNumber == 1 && operator_==NE) // printf("jne  >1\n");
                else if(labelNumber == 1 && operator_==GT) // printf("ja  >1\n");
                else if(labelNumber == 1 && operator_==LT) // printf("jb  >1\n");
                else if(labelNumber == 1 && operator_==GTE) // printf("jge  >1\n");
                else if(labelNumber == 1 && operator_==LTE) // printf("jbe  >1\n");
                else if(labelNumber == 2  && operator_==EQ) // printf("je  >2\n");
                else if(labelNumber == 2 && operator_==NE) // printf("jne  >2\n");
                else if(labelNumber == 2 && operator_==GT) // printf("ja  >2\n");
                else if(labelNumber == 2 && operator_==LT) // printf("jb  >2\n");
                else if(labelNumber == 2 && operator_==GTE) // printf("jge  >2\n");
                else if(labelNumber == 2 && operator_==LTE) // printf("jbe  >2\n");
                else if(labelNumber == 3  && operator_==EQ) // printf("je  >3\n");
                else if(labelNumber == 3 && operator_==NE) // printf("jne  >3\n");
                else if(labelNumber == 3 && operator_==GT) // printf("ja  >3\n");
                else if(labelNumber == 3 && operator_==LT) // printf("jb  >3\n");
                else if(labelNumber == 3 && operator_==GTE) // printf("jge  >3\n");
                else if(labelNumber == 3 && operator_==LTE) // printf("jbe  >3\n");
                else if(labelNumber == 4  && operator_==EQ) // printf("je  >4\n");
                else if(labelNumber == 4 && operator_==NE) // printf("jne  >4\n");
                else if(labelNumber == 4 && operator_==GT) // printf("ja  >4\n");
                else if(labelNumber == 4 && operator_==LT) // printf("jb  >4\n");
                else if(labelNumber == 4 && operator_==GTE) // printf("jge  >4\n");
                else if(labelNumber == 4 && operator_==LTE) // printf("jbe  >4\n");
                else if(labelNumber == 5  && operator_==EQ) // printf("je  >5\n");
                else if(labelNumber == 5 && operator_==NE) // printf("jne  >5\n");
                else if(labelNumber == 5 && operator_==GT) // printf("ja  >5\n");
                else if(labelNumber == 5 && operator_==LT) // printf("jb  >5\n");
                else if(labelNumber == 5 && operator_==GTE) // printf("jge  >5\n");
                else if(labelNumber == 5 && operator_==LTE) // printf("jbe  >5\n");
                else if(labelNumber == 6  && operator_==EQ) // printf("je  >6\n");
                else if(labelNumber == 6 && operator_==NE) // printf("jne  >6\n");
                else if(labelNumber == 6 && operator_==GT) // printf("ja  >6\n");
                else if(labelNumber == 6 && operator_==LT) // printf("jb  >6\n");
                else if(labelNumber == 6 && operator_==GTE) // printf("jge  >6\n");
                else if(labelNumber == 6 && operator_==LTE) // printf("jbe  >6\n");
                else if(labelNumber == 7  && operator_==EQ) // printf("je  >7\n");
                else if(labelNumber == 7 && operator_==NE) // printf("jne  >7\n");
                else if(labelNumber == 7 && operator_==GT) // printf("ja  >7\n");
                else if(labelNumber == 7 && operator_==LT) // printf("jb  >7\n");
                else if(labelNumber == 7 && operator_==GTE) // printf("jge  >7\n");
                else if(labelNumber == 7 && operator_==LTE) // printf("jbe  >7\n");
                else if(labelNumber == 8  && operator_==EQ) // printf("je  >8\n");
                else if(labelNumber == 8 && operator_==NE) // printf("jne  >8\n");
                else if(labelNumber == 8 && operator_==GT) // printf("ja  >8\n");
                else if(labelNumber == 8 && operator_==LT) // printf("jb  >8\n");
                else if(labelNumber == 8 && operator_==GTE) // printf("jge  >8\n");
                else if(labelNumber == 8 && operator_==LTE) // printf("jbe  >8\n");
                else if(labelNumber == 9  && operator_==EQ) // printf("je  >9\n");
                else if(labelNumber == 9 && operator_==NE) // printf("jne  >9\n");
                else if(labelNumber == 9 && operator_==GT) // printf("ja  >9\n");
                else if(labelNumber == 9 && operator_==LT) // printf("jb  >9\n");
                else if(labelNumber == 9 && operator_==GTE) // printf("jge  >9\n");
                else if(labelNumber == 9 && operator_==LTE) // printf("jbe  >9\n");
            }*/
}

void Assembly::conditionalJumpBackwardTo(int labelNumber, bool condition){
    if(condition == false){
        if(labelNumber == 1  && operator_==EQ)
			 //| jne  <1
			 dasm_put(Dst, 548);
#line 642 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
			 //| je  <1
			 dasm_put(Dst, 553);
#line 644 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
			 //| jbe  <1
			 dasm_put(Dst, 558);
#line 646 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jae  <1
			 dasm_put(Dst, 563);
#line 648 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jb  <1
			 dasm_put(Dst, 568);
#line 650 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| ja  <1
			 dasm_put(Dst, 573);
#line 652 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| jne  <2
			 dasm_put(Dst, 578);
#line 654 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| je  <2
			 dasm_put(Dst, 583);
#line 656 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| jbe  <2
			 dasm_put(Dst, 588);
#line 658 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jae  <2
			 dasm_put(Dst, 593);
#line 660 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jb  <2
			 dasm_put(Dst, 598);
#line 662 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| ja  <2
			 dasm_put(Dst, 603);
#line 664 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| jne  <3
			 dasm_put(Dst, 608);
#line 666 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| je  <3
			 dasm_put(Dst, 613);
#line 668 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| jbe  <3
			 dasm_put(Dst, 618);
#line 670 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jae  <3
			 dasm_put(Dst, 623);
#line 672 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jb  <3
			 dasm_put(Dst, 628);
#line 674 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| ja  <3
			 dasm_put(Dst, 633);
#line 676 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| jne  <4
			 dasm_put(Dst, 638);
#line 678 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| je  <4
			 dasm_put(Dst, 643);
#line 680 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| jbe  <4
			 dasm_put(Dst, 648);
#line 682 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jae  <4
			 dasm_put(Dst, 653);
#line 684 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jb  <4
			 dasm_put(Dst, 658);
#line 686 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| ja  <4
			 dasm_put(Dst, 663);
#line 688 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| jne  <5
			 dasm_put(Dst, 668);
#line 690 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| je  <5
			 dasm_put(Dst, 673);
#line 692 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| jbe  <5
			 dasm_put(Dst, 678);
#line 694 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jae  <5
			 dasm_put(Dst, 683);
#line 696 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jb  <5
			 dasm_put(Dst, 688);
#line 698 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| ja  <5
			 dasm_put(Dst, 693);
#line 700 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| jne  <6
			 dasm_put(Dst, 698);
#line 702 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| je  <6
			 dasm_put(Dst, 703);
#line 704 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| jbe  <6
			 dasm_put(Dst, 708);
#line 706 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jae  <6
			 dasm_put(Dst, 713);
#line 708 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jb  <6
			 dasm_put(Dst, 718);
#line 710 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| ja  <6
			 dasm_put(Dst, 723);
#line 712 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| jne  <7
			 dasm_put(Dst, 728);
#line 714 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| je  <7
			 dasm_put(Dst, 733);
#line 716 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| jbe  <7
			 dasm_put(Dst, 738);
#line 718 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jae  <7
			 dasm_put(Dst, 743);
#line 720 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jb  <7
			 dasm_put(Dst, 748);
#line 722 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| ja  <7
			 dasm_put(Dst, 753);
#line 724 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| jne  <8
			 dasm_put(Dst, 758);
#line 726 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| je  <8
			 dasm_put(Dst, 763);
#line 728 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| jbe  <8
			 dasm_put(Dst, 768);
#line 730 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jae  <8
			 dasm_put(Dst, 773);
#line 732 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jb  <8
			 dasm_put(Dst, 778);
#line 734 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| ja  <8
			 dasm_put(Dst, 783);
#line 736 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| jne  <9
			 dasm_put(Dst, 788);
#line 738 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| je  <9
			 dasm_put(Dst, 793);
#line 740 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| jbe  <9
			 dasm_put(Dst, 798);
#line 742 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jae  <9
			 dasm_put(Dst, 803);
#line 744 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jb  <9
			 dasm_put(Dst, 808);
#line 746 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| ja  <9
			 dasm_put(Dst, 813);
#line 748 "compiler/assembly/assembly.dasc"
    } else if(condition == true) {
        if(labelNumber == 1  && operator_==EQ)
			 //| je  <1
			 dasm_put(Dst, 553);
#line 751 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
			 //| jne  <1
			 dasm_put(Dst, 548);
#line 753 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
			 //| ja  <1
			 dasm_put(Dst, 573);
#line 755 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jb  <1
			 dasm_put(Dst, 568);
#line 757 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jge  <1
			 dasm_put(Dst, 818);
#line 759 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| jbe  <1
			 dasm_put(Dst, 558);
#line 761 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| je  <2
			 dasm_put(Dst, 583);
#line 763 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| jne  <2
			 dasm_put(Dst, 578);
#line 765 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| ja  <2
			 dasm_put(Dst, 603);
#line 767 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jb  <2
			 dasm_put(Dst, 598);
#line 769 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jge  <2
			 dasm_put(Dst, 823);
#line 771 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| jbe  <2
			 dasm_put(Dst, 588);
#line 773 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| je  <3
			 dasm_put(Dst, 613);
#line 775 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| jne  <3
			 dasm_put(Dst, 608);
#line 777 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| ja  <3
			 dasm_put(Dst, 633);
#line 779 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jb  <3
			 dasm_put(Dst, 628);
#line 781 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jge  <3
			 dasm_put(Dst, 828);
#line 783 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| jbe  <3
			 dasm_put(Dst, 618);
#line 785 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| je  <4
			 dasm_put(Dst, 643);
#line 787 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| jne  <4
			 dasm_put(Dst, 638);
#line 789 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| ja  <4
			 dasm_put(Dst, 663);
#line 791 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jb  <4
			 dasm_put(Dst, 658);
#line 793 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jge  <4
			 dasm_put(Dst, 833);
#line 795 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| jbe  <4
			 dasm_put(Dst, 648);
#line 797 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| je  <5
			 dasm_put(Dst, 673);
#line 799 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| jne  <5
			 dasm_put(Dst, 668);
#line 801 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| ja  <5
			 dasm_put(Dst, 693);
#line 803 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jb  <5
			 dasm_put(Dst, 688);
#line 805 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jge  <5
			 dasm_put(Dst, 838);
#line 807 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| jbe  <5
			 dasm_put(Dst, 678);
#line 809 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| je  <6
			 dasm_put(Dst, 703);
#line 811 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| jne  <6
			 dasm_put(Dst, 698);
#line 813 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| ja  <6
			 dasm_put(Dst, 723);
#line 815 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jb  <6
			 dasm_put(Dst, 718);
#line 817 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jge  <6
			 dasm_put(Dst, 843);
#line 819 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| jbe  <6
			 dasm_put(Dst, 708);
#line 821 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| je  <7
			 dasm_put(Dst, 733);
#line 823 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| jne  <7
			 dasm_put(Dst, 728);
#line 825 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| ja  <7
			 dasm_put(Dst, 753);
#line 827 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jb  <7
			 dasm_put(Dst, 748);
#line 829 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jge  <7
			 dasm_put(Dst, 848);
#line 831 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| jbe  <7
			 dasm_put(Dst, 738);
#line 833 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| je  <8
			 dasm_put(Dst, 763);
#line 835 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| jne  <8
			 dasm_put(Dst, 758);
#line 837 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| ja  <8
			 dasm_put(Dst, 783);
#line 839 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jb  <8
			 dasm_put(Dst, 778);
#line 841 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jge  <8
			 dasm_put(Dst, 853);
#line 843 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| jbe  <8
			 dasm_put(Dst, 768);
#line 845 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| je  <9
			 dasm_put(Dst, 793);
#line 847 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| jne  <9
			 dasm_put(Dst, 788);
#line 849 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| ja  <9
			 dasm_put(Dst, 813);
#line 851 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jb  <9
			 dasm_put(Dst, 808);
#line 853 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jge  <9
			 dasm_put(Dst, 858);
#line 855 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| jbe  <9
			 dasm_put(Dst, 798);
#line 857 "compiler/assembly/assembly.dasc"
	}
}


void Assembly::performCalculation(){

    switch(operator_){
        case ADD:
            {
                //| faddp st1
                dasm_put(Dst, 863);
#line 867 "compiler/assembly/assembly.dasc"
                // printf("faddp st1 \n");
                break;
            }
         case SUB:
            {
                //| fsubp st1
                dasm_put(Dst, 866);
#line 873 "compiler/assembly/assembly.dasc"
                // printf("fsubp st1 \n");
                break;
            }
         case MUL:
            {
                //| fmulp st1
                dasm_put(Dst, 870);
#line 879 "compiler/assembly/assembly.dasc"
                // printf("fmulp st1 \n");
                break;
            }
         case DIV:
            {
                //| fdivp st1
                dasm_put(Dst, 873);
#line 885 "compiler/assembly/assembly.dasc"
                // printf("fdivp st1 \n");
                break;
            }
         case NEG:
            {
                //| fchs
                dasm_put(Dst, 877);
#line 891 "compiler/assembly/assembly.dasc"
                // printf("fchs \n");
                break;
            }
         case SQRT:
            {
                //| fsqrt
                dasm_put(Dst, 880);
#line 897 "compiler/assembly/assembly.dasc"
                // printf("fsqrt \n");
                break;
            }
         case POW:
            {
                // printf("^: Operation not supported yet");
                exit(0);
            }
         case EQ:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 884);
#line 909 "compiler/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
          case NE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 884);
#line 917 "compiler/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
          case GT:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 884);
#line 925 "compiler/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
          case LT:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 884);
#line 933 "compiler/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
          case GTE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 884);
#line 941 "compiler/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
          case LTE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 884);
#line 949 "compiler/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
    }

    operator_ = EMPTY;
}



void Assembly::extractResult(){
     //| fstp qword [rbp-8]
     //| movlpd xmm0, qword [rbp-8]
     dasm_put(Dst, 890);
#line 963 "compiler/assembly/assembly.dasc"
}


void Assembly::epilogue(){
    //| pop rbp
    //| ret
    dasm_put(Dst, 901);
#line 969 "compiler/assembly/assembly.dasc"
}

dasm_gen_func Assembly::linkAndEncode(){
  size_t sz;
  void* buf;
  dasm_link(Dst, &sz);
  buf = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  dasm_encode(Dst, buf);
  mprotect(buf, sz, PROT_READ | PROT_EXEC);
  dasm_free(&d);
  return (dasm_gen_func) buf;
}
