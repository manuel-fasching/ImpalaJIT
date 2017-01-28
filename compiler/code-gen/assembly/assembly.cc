/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM x64 version 1.3.0
** DO NOT EDIT! The original file is in "compiler/code-gen/assembly/assembly.dasc".
*/

#line 1 "compiler/code-gen/assembly/assembly.dasc"
//
// Created by manuel on 06.11.16.
//

#include <assembly.hh>
#include <stdio.h>


//|.arch x64
#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 10 "compiler/code-gen/assembly/assembly.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 12 "compiler/code-gen/assembly/assembly.dasc"
//|.globals lbl_
enum {
  lbl__MAX
};
#line 13 "compiler/code-gen/assembly/assembly.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[985] = {
  85,72,137,229,72,137,232,72,131,232,16,255,221,4,37,237,255,221,24,72,131,
  232,8,255,102,15,19,69,252,248,221,69,252,248,255,102,15,19,77,252,248,221,
  69,252,248,255,102,15,19,85,252,248,221,69,252,248,255,102,15,19,93,252,248,
  221,69,252,248,255,102,15,19,101,252,248,221,69,252,248,255,102,15,19,109,
  252,248,221,69,252,248,255,102,15,19,117,252,248,221,69,252,248,255,102,15,
  19,125,252,248,221,69,252,248,255,221,133,233,255,221,93,252,248,102,15,18,
  69,252,248,255,221,93,252,248,102,15,18,77,252,248,255,221,93,252,248,102,
  15,18,85,252,248,255,221,93,252,248,102,15,18,93,252,248,255,221,93,252,248,
  102,15,18,101,252,248,255,221,93,252,248,102,15,18,109,252,248,255,221,93,
  252,248,102,15,18,117,252,248,255,221,93,252,248,102,15,18,125,252,248,255,
  221,157,233,255,248,1,255,248,2,255,248,3,255,248,4,255,248,5,255,248,6,255,
  248,7,255,248,8,255,248,9,255,252,233,244,247,255,252,233,244,248,255,252,
  233,244,249,255,252,233,244,250,255,252,233,244,251,255,252,233,244,252,255,
  252,233,244,253,255,252,233,244,254,255,252,233,244,255,255,252,233,244,1,
  255,252,233,244,2,255,252,233,244,3,255,252,233,244,4,255,252,233,244,5,255,
  252,233,244,6,255,252,233,244,7,255,252,233,244,8,255,252,233,244,9,255,15,
  133,244,247,255,15,132,244,247,255,15,134,244,247,255,15,131,244,247,255,
  15,130,244,247,255,15,135,244,247,255,15,133,244,248,255,15,132,244,248,255,
  15,134,244,248,255,15,131,244,248,255,15,130,244,248,255,15,135,244,248,255,
  15,133,244,249,255,15,132,244,249,255,15,134,244,249,255,15,131,244,249,255,
  15,130,244,249,255,15,135,244,249,255,15,133,244,250,255,15,132,244,250,255,
  15,134,244,250,255,15,131,244,250,255,15,130,244,250,255,15,135,244,250,255,
  15,133,244,251,255,15,132,244,251,255,15,134,244,251,255,15,131,244,251,255,
  15,130,244,251,255,15,135,244,251,255,15,133,244,252,255,15,132,244,252,255,
  15,134,244,252,255,15,131,244,252,255,15,130,244,252,255,15,135,244,252,255,
  15,133,244,253,255,15,132,244,253,255,15,134,244,253,255,15,131,244,253,255,
  15,130,244,253,255,15,135,244,253,255,15,133,244,254,255,15,132,244,254,255,
  15,134,244,254,255,15,131,244,254,255,15,130,244,254,255,15,135,244,254,255,
  15,133,244,255,255,15,132,244,255,255,15,134,244,255,255,15,131,244,255,255,
  15,130,244,255,255,15,135,244,255,255,15,141,244,247,255,15,141,244,248,255,
  15,141,244,249,255,15,141,244,250,255,15,141,244,251,255,15,141,244,252,255,
  15,141,244,253,255,15,141,244,254,255,15,141,244,255,255,15,133,244,1,255,
  15,132,244,1,255,15,134,244,1,255,15,131,244,1,255,15,130,244,1,255,15,135,
  244,1,255,15,133,244,2,255,15,132,244,2,255,15,134,244,2,255,15,131,244,2,
  255,15,130,244,2,255,15,135,244,2,255,15,133,244,3,255,15,132,244,3,255,15,
  134,244,3,255,15,131,244,3,255,15,130,244,3,255,15,135,244,3,255,15,133,244,
  4,255,15,132,244,4,255,15,134,244,4,255,15,131,244,4,255,15,130,244,4,255,
  15,135,244,4,255,15,133,244,5,255,15,132,244,5,255,15,134,244,5,255,15,131,
  244,5,255,15,130,244,5,255,15,135,244,5,255,15,133,244,6,255,15,132,244,6,
  255,15,134,244,6,255,15,131,244,6,255,15,130,244,6,255,15,135,244,6,255,15,
  133,244,7,255,15,132,244,7,255,15,134,244,7,255,15,131,244,7,255,15,130,244,
  7,255,15,135,244,7,255,15,133,244,8,255,15,132,244,8,255,15,134,244,8,255,
  15,131,244,8,255,15,130,244,8,255,15,135,244,8,255,15,133,244,9,255,15,132,
  244,9,255,15,134,244,9,255,15,131,244,9,255,15,130,244,9,255,15,135,244,9,
  255,15,141,244,1,255,15,141,244,2,255,15,141,244,3,255,15,141,244,4,255,15,
  141,244,5,255,15,141,244,6,255,15,141,244,7,255,15,141,244,8,255,15,141,244,
  9,255,217,224,255,222,193,255,222,252,233,255,222,201,255,222,252,249,255,
  217,252,250,255,223,252,241,221,216,255,93,195,255
};

#line 14 "compiler/code-gen/assembly/assembly.dasc"

#include <sys/mman.h>

#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif

Assembly::~Assembly()
{
    dasm_free(&d);
    delete labels;
    Dst = NULL;
    d = NULL;
    labels = NULL;
}

void Assembly::initialize() {
    dasm_init(&d, DASM_MAXSECTION);

    labels = (void **) operator new(lbl__MAX);
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
#line 47 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::pushConstantToFPUStack(double *value){
    //| fld qword [value]
    dasm_put(Dst, 12, value);
#line 51 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::storeLocalVariable() {
    //| fstp qword [rax]
    //| sub rax, 8
    dasm_put(Dst, 17);
#line 56 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::pushParameterToFPUStack(int index) {
    switch(index){
        case 0:
            {
                //| movlpd qword [rbp-8], xmm0
                //| fld qword [rbp-8]
                dasm_put(Dst, 24);
#line 64 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 1:
            {
                //| movlpd qword [rbp-8], xmm1
                //| fld qword [rbp-8]
                dasm_put(Dst, 35);
#line 70 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 2:
            {
                //| movlpd qword [rbp-8], xmm2
                //| fld qword [rbp-8]
                dasm_put(Dst, 46);
#line 76 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 3:
            {
                //| movlpd qword [rbp-8], xmm3
                //| fld qword [rbp-8]
                dasm_put(Dst, 57);
#line 82 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 4:
            {
                //| movlpd qword [rbp-8], xmm4
                //| fld qword [rbp-8]
                dasm_put(Dst, 68);
#line 88 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 5:
            {
                //| movlpd qword [rbp-8], xmm5
                //| fld qword [rbp-8]
                dasm_put(Dst, 79);
#line 94 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 6:
            {
                //| movlpd qword [rbp-8], xmm6
                //| fld qword [rbp-8]
                dasm_put(Dst, 90);
#line 100 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 7:
            {
                //| movlpd qword [rbp-8], xmm7
                //| fld qword [rbp-8]
                dasm_put(Dst, 101);
#line 106 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        default:
            {
                //| fld qword [rbp+(8+(index-7)*8)];
                dasm_put(Dst, 112, (8+(index-7)*8));
#line 111 "compiler/code-gen/assembly/assembly.dasc"
            }
    }
}

void Assembly::replaceParameter(int index) {
    switch(index){
        case 0:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm0, qword [rbp-8]
                dasm_put(Dst, 116);
#line 121 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 1:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm1, qword [rbp-8]
                dasm_put(Dst, 127);
#line 127 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 2:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm2, qword [rbp-8]
                dasm_put(Dst, 138);
#line 133 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 3:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm3, qword [rbp-8]
                dasm_put(Dst, 149);
#line 139 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 4:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm4, qword [rbp-8]
                dasm_put(Dst, 160);
#line 145 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 5:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm5, qword [rbp-8]
                dasm_put(Dst, 171);
#line 151 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 6:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm6, qword [rbp-8]
                dasm_put(Dst, 182);
#line 157 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 7:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm7, qword [rbp-8]
                dasm_put(Dst, 193);
#line 163 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        default:
            {
                //| fstp qword [rbp+(8+(index-7)*8)];
                dasm_put(Dst, 204, (8+(index-7)*8));
#line 168 "compiler/code-gen/assembly/assembly.dasc"
            }
    }
}

void Assembly::pushLocalVariableToFPUStack(int index) {
// printf("Val: %u\n", index);
    //| fld qword [rbp-(16+index*8)];
    dasm_put(Dst, 112, -(16+index*8));
#line 175 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::replaceLocalVariable(int index) {
// printf("Val: %u\n", index);
    //| fstp qword [rbp-(16+index*8)];
    dasm_put(Dst, 204, -(16+index*8));
#line 180 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::addLocalLabel(int labelNumber) {
    switch(labelNumber) {
        case 1:
            {
                //| 1:
                dasm_put(Dst, 208);
#line 187 "compiler/code-gen/assembly/assembly.dasc"
                // printf("1: \n");
                break;
            }
        case 2:
            {
                //| 2:
                dasm_put(Dst, 211);
#line 193 "compiler/code-gen/assembly/assembly.dasc"
                // printf("2: \n");
                break;
            }
        case 3:
            {
                //| 3:
                dasm_put(Dst, 214);
#line 199 "compiler/code-gen/assembly/assembly.dasc"
                // printf("3: \n");
                break;
            }
        case 4:
            {
                //| 4:
                dasm_put(Dst, 217);
#line 205 "compiler/code-gen/assembly/assembly.dasc"
                // printf("4: \n");
                break;
            }
        case 5:
            {
                //| 5:
                dasm_put(Dst, 220);
#line 211 "compiler/code-gen/assembly/assembly.dasc"
                // printf("5: \n");
                break;
            }
        case 6:
            {
                //| 6:
                dasm_put(Dst, 223);
#line 217 "compiler/code-gen/assembly/assembly.dasc"
                // printf("6: \n");
                break;
            }
        case 7:
            {
                //| 7:
                dasm_put(Dst, 226);
#line 223 "compiler/code-gen/assembly/assembly.dasc"
                // printf("7: \n");
                break;
            }
        case 8:
            {
                //| 8:
                dasm_put(Dst, 229);
#line 229 "compiler/code-gen/assembly/assembly.dasc"
                // printf("8: \n");
                break;
            }
        case 9:
            {
                //| 9:
                dasm_put(Dst, 232);
#line 235 "compiler/code-gen/assembly/assembly.dasc"
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
                    dasm_put(Dst, 235);
#line 246 "compiler/code-gen/assembly/assembly.dasc"
                    // printf(">1 \n");
                    break;
                }
            case 2:
                {
                    //| jmp >2
                    dasm_put(Dst, 240);
#line 252 "compiler/code-gen/assembly/assembly.dasc"
                    // printf(">2 \n");
                    break;
                }
            case 3:
                {
                    //| jmp >3
                    dasm_put(Dst, 245);
#line 258 "compiler/code-gen/assembly/assembly.dasc"
                    // printf(">3 \n");
                    break;
                }
            case 4:
                {
                    //| jmp >4
                    dasm_put(Dst, 250);
#line 264 "compiler/code-gen/assembly/assembly.dasc"
                    // printf(">4 \n");
                    break;
                }
            case 5:
                {
                    //| jmp >5
                    dasm_put(Dst, 255);
#line 270 "compiler/code-gen/assembly/assembly.dasc"
                    // printf(">5 \n");
                    break;
                }
            case 6:
                {
                    //| jmp >6
                    dasm_put(Dst, 260);
#line 276 "compiler/code-gen/assembly/assembly.dasc"
                    // printf(">6 \n");
                    break;
                }
            case 7:
                {
                    //| jmp >7
                    dasm_put(Dst, 265);
#line 282 "compiler/code-gen/assembly/assembly.dasc"
                    // printf(">7 \n");
                    break;
                }
            case 8:
                {
                    //| jmp >8
                    dasm_put(Dst, 270);
#line 288 "compiler/code-gen/assembly/assembly.dasc"
                    // printf(">8 \n");
                    break;
                }
            case 9:
                {
                    //| jmp >9
                    dasm_put(Dst, 275);
#line 294 "compiler/code-gen/assembly/assembly.dasc"
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
                    dasm_put(Dst, 280);
#line 306 "compiler/code-gen/assembly/assembly.dasc"
                    // printf("<1 \n");
                    break;
                }
            case 2:
                {
                    //| jmp <2
                    dasm_put(Dst, 285);
#line 312 "compiler/code-gen/assembly/assembly.dasc"
                    // printf("<2 \n");
                    break;
                }
            case 3:
                {
                    //| jmp <3
                    dasm_put(Dst, 290);
#line 318 "compiler/code-gen/assembly/assembly.dasc"
                    // printf("<3 \n");
                    break;
                }
            case 4:
                {
                    //| jmp <4
                    dasm_put(Dst, 295);
#line 324 "compiler/code-gen/assembly/assembly.dasc"
                    // printf("<4 \n");
                    break;
                }
            case 5:
                {
                    //| jmp <5
                    dasm_put(Dst, 300);
#line 330 "compiler/code-gen/assembly/assembly.dasc"
                    // printf("<5 \n");
                    break;
                }
            case 6:
                {
                    //| jmp <6
                    dasm_put(Dst, 305);
#line 336 "compiler/code-gen/assembly/assembly.dasc"
                    // printf("<6 \n");
                    break;
                }
            case 7:
                {
                    //| jmp <7
                    dasm_put(Dst, 310);
#line 342 "compiler/code-gen/assembly/assembly.dasc"
                    // printf("<7 \n");
                    break;
                }
            case 8:
                {
                    //| jmp <8
                    dasm_put(Dst, 315);
#line 348 "compiler/code-gen/assembly/assembly.dasc"
                    // printf("<8 \n");
                    break;
                }
            case 9:
                {
                    //| jmp <9
                    dasm_put(Dst, 320);
#line 354 "compiler/code-gen/assembly/assembly.dasc"
                    // printf("<9 \n");
                    break;
                }
        }
}


void Assembly::conditionalJumpForwardTo(int labelNumber, bool condition, CompareOperatorType operator_){
    if(condition == false){
        if(labelNumber == 1  && operator_==EQ)
            //| jne  >1
            dasm_put(Dst, 325);
#line 365 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
            //| je  >1
            dasm_put(Dst, 330);
#line 367 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
            //| jbe  >1
            dasm_put(Dst, 335);
#line 369 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
            //| jae  >1
            dasm_put(Dst, 340);
#line 371 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
            //| jb  >1
            dasm_put(Dst, 345);
#line 373 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
            //| ja  >1
            dasm_put(Dst, 350);
#line 375 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
            //| jne  >2
            dasm_put(Dst, 355);
#line 377 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
            //| je  >2
            dasm_put(Dst, 360);
#line 379 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
            //| jbe  >2
            dasm_put(Dst, 365);
#line 381 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
            //| jae  >2
            dasm_put(Dst, 370);
#line 383 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
            //| jb  >2
            dasm_put(Dst, 375);
#line 385 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
            //| ja  >2
            dasm_put(Dst, 380);
#line 387 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
            //| jne  >3
            dasm_put(Dst, 385);
#line 389 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
            //| je  >3
            dasm_put(Dst, 390);
#line 391 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
            //| jbe  >3
            dasm_put(Dst, 395);
#line 393 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
            //| jae  >3
            dasm_put(Dst, 400);
#line 395 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
            //| jb  >3
            dasm_put(Dst, 405);
#line 397 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
            //| ja  >3
            dasm_put(Dst, 410);
#line 399 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
            //| jne  >4
            dasm_put(Dst, 415);
#line 401 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
            //| je  >4
            dasm_put(Dst, 420);
#line 403 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
            //| jbe  >4
            dasm_put(Dst, 425);
#line 405 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
            //| jae  >4
            dasm_put(Dst, 430);
#line 407 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
            //| jb  >4
            dasm_put(Dst, 435);
#line 409 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
            //| ja  >4
            dasm_put(Dst, 440);
#line 411 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
            //| jne  >5
            dasm_put(Dst, 445);
#line 413 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
            //| je  >5
            dasm_put(Dst, 450);
#line 415 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
            //| jbe  >5
            dasm_put(Dst, 455);
#line 417 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
            //| jae  >5
            dasm_put(Dst, 460);
#line 419 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
            //| jb  >5
            dasm_put(Dst, 465);
#line 421 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
            //| ja  >5
            dasm_put(Dst, 470);
#line 423 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
            //| jne  >6
            dasm_put(Dst, 475);
#line 425 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
            //| je  >6
            dasm_put(Dst, 480);
#line 427 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
            //| jbe  >6
            dasm_put(Dst, 485);
#line 429 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
            //| jae  >6
            dasm_put(Dst, 490);
#line 431 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
            //| jb  >6
            dasm_put(Dst, 495);
#line 433 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
            //| ja  >6
            dasm_put(Dst, 500);
#line 435 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
            //| jne  >7
            dasm_put(Dst, 505);
#line 437 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
            //| je  >7
            dasm_put(Dst, 510);
#line 439 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
            //| jbe  >7
            dasm_put(Dst, 515);
#line 441 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
            //| jae  >7
            dasm_put(Dst, 520);
#line 443 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
            //| jb  >7
            dasm_put(Dst, 525);
#line 445 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
            //| ja  >7
            dasm_put(Dst, 530);
#line 447 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
            //| jne  >8
            dasm_put(Dst, 535);
#line 449 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
            //| je  >8
            dasm_put(Dst, 540);
#line 451 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
            //| jbe  >8
            dasm_put(Dst, 545);
#line 453 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
            //| jae  >8
            dasm_put(Dst, 550);
#line 455 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
            //| jb  >8
            dasm_put(Dst, 555);
#line 457 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
            //| ja  >8
            dasm_put(Dst, 560);
#line 459 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
            //| jne  >9
            dasm_put(Dst, 565);
#line 461 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
            //| je  >9
            dasm_put(Dst, 570);
#line 463 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
            //| jbe  >9
            dasm_put(Dst, 575);
#line 465 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
            //| jae  >9
            dasm_put(Dst, 580);
#line 467 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
            //| jb  >9
            dasm_put(Dst, 585);
#line 469 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
            //| ja  >9
            dasm_put(Dst, 590);
#line 471 "compiler/code-gen/assembly/assembly.dasc"
    }
    else if(condition == true){
        if(labelNumber == 1  && operator_==EQ) 
            //| je  >1
            dasm_put(Dst, 330);
#line 475 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE) 
            //| jne  >1
            dasm_put(Dst, 325);
#line 477 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT) 
            //| ja  >1
            dasm_put(Dst, 350);
#line 479 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jb  >1
			 dasm_put(Dst, 345);
#line 481 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jge  >1
			 dasm_put(Dst, 595);
#line 483 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| jbe  >1
			 dasm_put(Dst, 335);
#line 485 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| je  >2
			 dasm_put(Dst, 360);
#line 487 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| jne  >2
			 dasm_put(Dst, 355);
#line 489 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| ja  >2
			 dasm_put(Dst, 380);
#line 491 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jb  >2
			 dasm_put(Dst, 375);
#line 493 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jge  >2
			 dasm_put(Dst, 600);
#line 495 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| jbe  >2
			 dasm_put(Dst, 365);
#line 497 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| je  >3
			 dasm_put(Dst, 390);
#line 499 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| jne  >3
			 dasm_put(Dst, 385);
#line 501 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| ja  >3
			 dasm_put(Dst, 410);
#line 503 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jb  >3
			 dasm_put(Dst, 405);
#line 505 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jge  >3
			 dasm_put(Dst, 605);
#line 507 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| jbe  >3
			 dasm_put(Dst, 395);
#line 509 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| je  >4
			 dasm_put(Dst, 420);
#line 511 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| jne  >4
			 dasm_put(Dst, 415);
#line 513 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| ja  >4
			 dasm_put(Dst, 440);
#line 515 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jb  >4
			 dasm_put(Dst, 435);
#line 517 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jge  >4
			 dasm_put(Dst, 610);
#line 519 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| jbe  >4
			 dasm_put(Dst, 425);
#line 521 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| je  >5
			 dasm_put(Dst, 450);
#line 523 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| jne  >5
			 dasm_put(Dst, 445);
#line 525 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| ja  >5
			 dasm_put(Dst, 470);
#line 527 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jb  >5
			 dasm_put(Dst, 465);
#line 529 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jge  >5
			 dasm_put(Dst, 615);
#line 531 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| jbe  >5
			 dasm_put(Dst, 455);
#line 533 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| je  >6
			 dasm_put(Dst, 480);
#line 535 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| jne  >6
			 dasm_put(Dst, 475);
#line 537 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| ja  >6
			 dasm_put(Dst, 500);
#line 539 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jb  >6
			 dasm_put(Dst, 495);
#line 541 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jge  >6
			 dasm_put(Dst, 620);
#line 543 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| jbe  >6
			 dasm_put(Dst, 485);
#line 545 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| je  >7
			 dasm_put(Dst, 510);
#line 547 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| jne  >7
			 dasm_put(Dst, 505);
#line 549 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| ja  >7
			 dasm_put(Dst, 530);
#line 551 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jb  >7
			 dasm_put(Dst, 525);
#line 553 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jge  >7
			 dasm_put(Dst, 625);
#line 555 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| jbe  >7
			 dasm_put(Dst, 515);
#line 557 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| je  >8
			 dasm_put(Dst, 540);
#line 559 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| jne  >8
			 dasm_put(Dst, 535);
#line 561 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| ja  >8
			 dasm_put(Dst, 560);
#line 563 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jb  >8
			 dasm_put(Dst, 555);
#line 565 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jge  >8
			 dasm_put(Dst, 630);
#line 567 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| jbe  >8
			 dasm_put(Dst, 545);
#line 569 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| je  >9
			 dasm_put(Dst, 570);
#line 571 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| jne  >9
			 dasm_put(Dst, 565);
#line 573 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| ja  >9
			 dasm_put(Dst, 590);
#line 575 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jb  >9
			 dasm_put(Dst, 585);
#line 577 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jge  >9
			 dasm_put(Dst, 635);
#line 579 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| jbe  >9
			 dasm_put(Dst, 575);
#line 581 "compiler/code-gen/assembly/assembly.dasc"
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

void Assembly::conditionalJumpBackwardTo(int labelNumber, bool condition, CompareOperatorType operator_){
    if(condition == false){
        if(labelNumber == 1  && operator_==EQ)
			 //| jne  <1
			 dasm_put(Dst, 640);
#line 700 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
			 //| je  <1
			 dasm_put(Dst, 645);
#line 702 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
			 //| jbe  <1
			 dasm_put(Dst, 650);
#line 704 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jae  <1
			 dasm_put(Dst, 655);
#line 706 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jb  <1
			 dasm_put(Dst, 660);
#line 708 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| ja  <1
			 dasm_put(Dst, 665);
#line 710 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| jne  <2
			 dasm_put(Dst, 670);
#line 712 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| je  <2
			 dasm_put(Dst, 675);
#line 714 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| jbe  <2
			 dasm_put(Dst, 680);
#line 716 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jae  <2
			 dasm_put(Dst, 685);
#line 718 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jb  <2
			 dasm_put(Dst, 690);
#line 720 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| ja  <2
			 dasm_put(Dst, 695);
#line 722 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| jne  <3
			 dasm_put(Dst, 700);
#line 724 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| je  <3
			 dasm_put(Dst, 705);
#line 726 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| jbe  <3
			 dasm_put(Dst, 710);
#line 728 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jae  <3
			 dasm_put(Dst, 715);
#line 730 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jb  <3
			 dasm_put(Dst, 720);
#line 732 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| ja  <3
			 dasm_put(Dst, 725);
#line 734 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| jne  <4
			 dasm_put(Dst, 730);
#line 736 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| je  <4
			 dasm_put(Dst, 735);
#line 738 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| jbe  <4
			 dasm_put(Dst, 740);
#line 740 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jae  <4
			 dasm_put(Dst, 745);
#line 742 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jb  <4
			 dasm_put(Dst, 750);
#line 744 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| ja  <4
			 dasm_put(Dst, 755);
#line 746 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| jne  <5
			 dasm_put(Dst, 760);
#line 748 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| je  <5
			 dasm_put(Dst, 765);
#line 750 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| jbe  <5
			 dasm_put(Dst, 770);
#line 752 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jae  <5
			 dasm_put(Dst, 775);
#line 754 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jb  <5
			 dasm_put(Dst, 780);
#line 756 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| ja  <5
			 dasm_put(Dst, 785);
#line 758 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| jne  <6
			 dasm_put(Dst, 790);
#line 760 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| je  <6
			 dasm_put(Dst, 795);
#line 762 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| jbe  <6
			 dasm_put(Dst, 800);
#line 764 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jae  <6
			 dasm_put(Dst, 805);
#line 766 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jb  <6
			 dasm_put(Dst, 810);
#line 768 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| ja  <6
			 dasm_put(Dst, 815);
#line 770 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| jne  <7
			 dasm_put(Dst, 820);
#line 772 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| je  <7
			 dasm_put(Dst, 825);
#line 774 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| jbe  <7
			 dasm_put(Dst, 830);
#line 776 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jae  <7
			 dasm_put(Dst, 835);
#line 778 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jb  <7
			 dasm_put(Dst, 840);
#line 780 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| ja  <7
			 dasm_put(Dst, 845);
#line 782 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| jne  <8
			 dasm_put(Dst, 850);
#line 784 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| je  <8
			 dasm_put(Dst, 855);
#line 786 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| jbe  <8
			 dasm_put(Dst, 860);
#line 788 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jae  <8
			 dasm_put(Dst, 865);
#line 790 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jb  <8
			 dasm_put(Dst, 870);
#line 792 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| ja  <8
			 dasm_put(Dst, 875);
#line 794 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| jne  <9
			 dasm_put(Dst, 880);
#line 796 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| je  <9
			 dasm_put(Dst, 885);
#line 798 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| jbe  <9
			 dasm_put(Dst, 890);
#line 800 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jae  <9
			 dasm_put(Dst, 895);
#line 802 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jb  <9
			 dasm_put(Dst, 900);
#line 804 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| ja  <9
			 dasm_put(Dst, 905);
#line 806 "compiler/code-gen/assembly/assembly.dasc"
    } else if(condition == true) {
        if(labelNumber == 1  && operator_==EQ)
			 //| je  <1
			 dasm_put(Dst, 645);
#line 809 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
			 //| jne  <1
			 dasm_put(Dst, 640);
#line 811 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
			 //| ja  <1
			 dasm_put(Dst, 665);
#line 813 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jb  <1
			 dasm_put(Dst, 660);
#line 815 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jge  <1
			 dasm_put(Dst, 910);
#line 817 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| jbe  <1
			 dasm_put(Dst, 650);
#line 819 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| je  <2
			 dasm_put(Dst, 675);
#line 821 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| jne  <2
			 dasm_put(Dst, 670);
#line 823 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| ja  <2
			 dasm_put(Dst, 695);
#line 825 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jb  <2
			 dasm_put(Dst, 690);
#line 827 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jge  <2
			 dasm_put(Dst, 915);
#line 829 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| jbe  <2
			 dasm_put(Dst, 680);
#line 831 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| je  <3
			 dasm_put(Dst, 705);
#line 833 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| jne  <3
			 dasm_put(Dst, 700);
#line 835 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| ja  <3
			 dasm_put(Dst, 725);
#line 837 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jb  <3
			 dasm_put(Dst, 720);
#line 839 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jge  <3
			 dasm_put(Dst, 920);
#line 841 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| jbe  <3
			 dasm_put(Dst, 710);
#line 843 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| je  <4
			 dasm_put(Dst, 735);
#line 845 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| jne  <4
			 dasm_put(Dst, 730);
#line 847 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| ja  <4
			 dasm_put(Dst, 755);
#line 849 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jb  <4
			 dasm_put(Dst, 750);
#line 851 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jge  <4
			 dasm_put(Dst, 925);
#line 853 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| jbe  <4
			 dasm_put(Dst, 740);
#line 855 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| je  <5
			 dasm_put(Dst, 765);
#line 857 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| jne  <5
			 dasm_put(Dst, 760);
#line 859 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| ja  <5
			 dasm_put(Dst, 785);
#line 861 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jb  <5
			 dasm_put(Dst, 780);
#line 863 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jge  <5
			 dasm_put(Dst, 930);
#line 865 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| jbe  <5
			 dasm_put(Dst, 770);
#line 867 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| je  <6
			 dasm_put(Dst, 795);
#line 869 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| jne  <6
			 dasm_put(Dst, 790);
#line 871 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| ja  <6
			 dasm_put(Dst, 815);
#line 873 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jb  <6
			 dasm_put(Dst, 810);
#line 875 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jge  <6
			 dasm_put(Dst, 935);
#line 877 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| jbe  <6
			 dasm_put(Dst, 800);
#line 879 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| je  <7
			 dasm_put(Dst, 825);
#line 881 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| jne  <7
			 dasm_put(Dst, 820);
#line 883 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| ja  <7
			 dasm_put(Dst, 845);
#line 885 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jb  <7
			 dasm_put(Dst, 840);
#line 887 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jge  <7
			 dasm_put(Dst, 940);
#line 889 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| jbe  <7
			 dasm_put(Dst, 830);
#line 891 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| je  <8
			 dasm_put(Dst, 855);
#line 893 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| jne  <8
			 dasm_put(Dst, 850);
#line 895 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| ja  <8
			 dasm_put(Dst, 875);
#line 897 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jb  <8
			 dasm_put(Dst, 870);
#line 899 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jge  <8
			 dasm_put(Dst, 945);
#line 901 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| jbe  <8
			 dasm_put(Dst, 860);
#line 903 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| je  <9
			 dasm_put(Dst, 885);
#line 905 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| jne  <9
			 dasm_put(Dst, 880);
#line 907 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| ja  <9
			 dasm_put(Dst, 905);
#line 909 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jb  <9
			 dasm_put(Dst, 900);
#line 911 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jge  <9
			 dasm_put(Dst, 950);
#line 913 "compiler/code-gen/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| jbe  <9
			 dasm_put(Dst, 890);
#line 915 "compiler/code-gen/assembly/assembly.dasc"
	}
}


void Assembly::performNegation(){
    //| fchs
    dasm_put(Dst, 955);
#line 921 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateAddition(){
    //| faddp st1
    dasm_put(Dst, 958);
#line 925 "compiler/code-gen/assembly/assembly.dasc"
    // printf("faddp st1 \n");
}

void Assembly::calculateSubtraction(){
    //| fsubp st1
    dasm_put(Dst, 961);
#line 930 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateMultiplication(){
    //| fmulp st1
    dasm_put(Dst, 965);
#line 934 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateDivision(){
    //| fdivp st1
    dasm_put(Dst, 968);
#line 938 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculatePower(){
    printf("^: Operation not supported yet");
    exit(0);
}

void Assembly::calculateSQRT(){
    //| fsqrt
    dasm_put(Dst, 972);
#line 947 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::performComparison(CompareOperatorType _operator){
        switch(_operator) {
          case EQ:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 976);
#line 955 "compiler/code-gen/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
          case NE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 976);
#line 963 "compiler/code-gen/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
          case GT:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 976);
#line 971 "compiler/code-gen/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
          case LT:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 976);
#line 979 "compiler/code-gen/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
          case GTE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 976);
#line 987 "compiler/code-gen/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
          case LTE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 976);
#line 995 "compiler/code-gen/assembly/assembly.dasc"
                // printf("fcomip st1 \n");
                // printf("fpop \n");
                break;
            }
        }
}

void Assembly::extractResult(){
     //| fstp qword [rbp-8]
     //| movlpd xmm0, qword [rbp-8]
     dasm_put(Dst, 116);
#line 1005 "compiler/code-gen/assembly/assembly.dasc"
}


void Assembly::epilogue(){
    //| pop rbp
    //| ret
    dasm_put(Dst, 982);
#line 1011 "compiler/code-gen/assembly/assembly.dasc"
}

dasm_gen_func Assembly::linkAndEncode(){
  size_t sz;
  void* buf;
  dasm_link(Dst, &sz);
  buf = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  dasm_encode(Dst, buf);
  mprotect(buf, sz, PROT_READ | PROT_EXEC);
  return (dasm_gen_func) buf;
}
