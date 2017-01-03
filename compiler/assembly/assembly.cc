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
#line 10 "compiler/assembly/assembly.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 12 "compiler/assembly/assembly.dasc"
//|.globals lbl_
enum {
  lbl__MAX
};
#line 13 "compiler/assembly/assembly.dasc"
//|.actionlist bf_actions
static const unsigned char bf_actions[796] = {
  221,4,37,237,255,221,28,37,237,255,248,1,255,248,2,255,248,3,255,248,4,255,
  248,5,255,248,6,255,248,7,255,248,8,255,248,9,255,252,233,244,247,255,252,
  233,244,248,255,252,233,244,249,255,252,233,244,250,255,252,233,244,251,255,
  252,233,244,252,255,252,233,244,253,255,252,233,244,254,255,252,233,244,255,
  255,252,233,244,1,255,252,233,244,2,255,252,233,244,3,255,252,233,244,4,255,
  252,233,244,5,255,252,233,244,6,255,252,233,244,7,255,252,233,244,8,255,252,
  233,244,9,255,15,133,244,247,255,15,132,244,247,255,15,134,244,247,255,15,
  131,244,247,255,15,130,244,247,255,15,135,244,247,255,15,133,244,248,255,
  15,132,244,248,255,15,134,244,248,255,15,131,244,248,255,15,130,244,248,255,
  15,135,244,248,255,15,133,244,249,255,15,132,244,249,255,15,134,244,249,255,
  15,131,244,249,255,15,130,244,249,255,15,135,244,249,255,15,133,244,250,255,
  15,132,244,250,255,15,134,244,250,255,15,131,244,250,255,15,130,244,250,255,
  15,135,244,250,255,15,133,244,251,255,15,132,244,251,255,15,134,244,251,255,
  15,131,244,251,255,15,130,244,251,255,15,135,244,251,255,15,133,244,252,255,
  15,132,244,252,255,15,134,244,252,255,15,131,244,252,255,15,130,244,252,255,
  15,135,244,252,255,15,133,244,253,255,15,132,244,253,255,15,134,244,253,255,
  15,131,244,253,255,15,130,244,253,255,15,135,244,253,255,15,133,244,254,255,
  15,132,244,254,255,15,134,244,254,255,15,131,244,254,255,15,130,244,254,255,
  15,135,244,254,255,15,133,244,255,255,15,132,244,255,255,15,134,244,255,255,
  15,131,244,255,255,15,130,244,255,255,15,135,244,255,255,15,141,244,247,255,
  15,141,244,248,255,15,141,244,249,255,15,141,244,250,255,15,141,244,251,255,
  15,141,244,252,255,15,141,244,253,255,15,141,244,254,255,15,141,244,255,255,
  15,133,244,1,255,15,132,244,1,255,15,134,244,1,255,15,131,244,1,255,15,130,
  244,1,255,15,135,244,1,255,15,133,244,2,255,15,132,244,2,255,15,134,244,2,
  255,15,131,244,2,255,15,130,244,2,255,15,135,244,2,255,15,133,244,3,255,15,
  132,244,3,255,15,134,244,3,255,15,131,244,3,255,15,130,244,3,255,15,135,244,
  3,255,15,133,244,4,255,15,132,244,4,255,15,134,244,4,255,15,131,244,4,255,
  15,130,244,4,255,15,135,244,4,255,15,133,244,5,255,15,132,244,5,255,15,134,
  244,5,255,15,131,244,5,255,15,130,244,5,255,15,135,244,5,255,15,133,244,6,
  255,15,132,244,6,255,15,134,244,6,255,15,131,244,6,255,15,130,244,6,255,15,
  135,244,6,255,15,133,244,7,255,15,132,244,7,255,15,134,244,7,255,15,131,244,
  7,255,15,130,244,7,255,15,135,244,7,255,15,133,244,8,255,15,132,244,8,255,
  15,134,244,8,255,15,131,244,8,255,15,130,244,8,255,15,135,244,8,255,15,133,
  244,9,255,15,132,244,9,255,15,134,244,9,255,15,131,244,9,255,15,130,244,9,
  255,15,135,244,9,255,15,141,244,1,255,15,141,244,2,255,15,141,244,3,255,15,
  141,244,4,255,15,141,244,5,255,15,141,244,6,255,15,141,244,7,255,15,141,244,
  8,255,15,141,244,9,255,221,28,37,237,102,15,18,4,37,237,195,255,222,193,255,
  222,252,233,255,222,201,255,222,252,249,255,217,224,255,217,252,250,255,223,
  252,241,221,216,255
};

#line 14 "compiler/assembly/assembly.dasc"

#if _WIN32
#include <Windows.h>
#else
#include <sys/mman.h>

#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif
#endif


dasm_State* d;
void** labels;
dasm_State** Dst;
int operator_;

Assembly::Assembly(){
    dasm_init(&d, DASM_MAXSECTION);

    labels = (void**) malloc(lbl__MAX);
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, bf_actions);

    Dst = &d;
}

void Assembly::push(double* value){
    //| fld qword [value]
    dasm_put(Dst, 0, value);
#line 44 "compiler/assembly/assembly.dasc"
    printf("fld qword [%f] \n", *value);
}

double* Assembly::pull() {
    double* container = (double*) malloc(sizeof(double));
    //| fstp qword [container]
    dasm_put(Dst, 5, container);
#line 50 "compiler/assembly/assembly.dasc"
    return container;
}

void Assembly::addLocalLabel(int labelNumber) {
    switch(labelNumber) {
        case 1:
            {
                //| 1:
                dasm_put(Dst, 10);
#line 58 "compiler/assembly/assembly.dasc"
                printf("1: \n");
                break;
            }
        case 2:
            {
                //| 2:
                dasm_put(Dst, 13);
#line 64 "compiler/assembly/assembly.dasc"
                printf("2: \n");
                break;
            }
        case 3:
            {
                //| 3:
                dasm_put(Dst, 16);
#line 70 "compiler/assembly/assembly.dasc"
                printf("3: \n");
                break;
            }
        case 4:
            {
                //| 4:
                dasm_put(Dst, 19);
#line 76 "compiler/assembly/assembly.dasc"
                printf("4: \n");
                break;
            }
        case 5:
            {
                //| 5:
                dasm_put(Dst, 22);
#line 82 "compiler/assembly/assembly.dasc"
                printf("5: \n");
                break;
            }
        case 6:
            {
                //| 6:
                dasm_put(Dst, 25);
#line 88 "compiler/assembly/assembly.dasc"
                printf("6: \n");
                break;
            }
        case 7:
            {
                //| 7:
                dasm_put(Dst, 28);
#line 94 "compiler/assembly/assembly.dasc"
                printf("7: \n");
                break;
            }
        case 8:
            {
                //| 8:
                dasm_put(Dst, 31);
#line 100 "compiler/assembly/assembly.dasc"
                printf("8: \n");
                break;
            }
        case 9:
            {
                //| 9:
                dasm_put(Dst, 34);
#line 106 "compiler/assembly/assembly.dasc"
                printf("9: \n");
                break;
            }
    }
}

void Assembly::jumpForwardTo(int labelNumber) {
    switch(labelNumber) {
            case 1:
                {
                    //| jmp >1
                    dasm_put(Dst, 37);
#line 117 "compiler/assembly/assembly.dasc"
                    printf(">1 \n");
                    break;
                }
            case 2:
                {
                    //| jmp >2
                    dasm_put(Dst, 42);
#line 123 "compiler/assembly/assembly.dasc"
                    printf(">2 \n");
                    break;
                }
            case 3:
                {
                    //| jmp >3
                    dasm_put(Dst, 47);
#line 129 "compiler/assembly/assembly.dasc"
                    printf(">3 \n");
                    break;
                }
            case 4:
                {
                    //| jmp >4
                    dasm_put(Dst, 52);
#line 135 "compiler/assembly/assembly.dasc"
                    printf(">4 \n");
                    break;
                }
            case 5:
                {
                    //| jmp >5
                    dasm_put(Dst, 57);
#line 141 "compiler/assembly/assembly.dasc"
                    printf(">5 \n");
                    break;
                }
            case 6:
                {
                    //| jmp >6
                    dasm_put(Dst, 62);
#line 147 "compiler/assembly/assembly.dasc"
                    printf(">6 \n");
                    break;
                }
            case 7:
                {
                    //| jmp >7
                    dasm_put(Dst, 67);
#line 153 "compiler/assembly/assembly.dasc"
                    printf(">7 \n");
                    break;
                }
            case 8:
                {
                    //| jmp >8
                    dasm_put(Dst, 72);
#line 159 "compiler/assembly/assembly.dasc"
                    printf(">8 \n");
                    break;
                }
            case 9:
                {
                    //| jmp >9
                    dasm_put(Dst, 77);
#line 165 "compiler/assembly/assembly.dasc"
                    printf(">9 \n");
                    break;
                }
        }
}


void Assembly::jumpBackwardTo(int labelNumber) {
    switch(labelNumber) {
            case 1:
                {
                    //| jmp <1
                    dasm_put(Dst, 82);
#line 177 "compiler/assembly/assembly.dasc"
                    printf("<1 \n");
                    break;
                }
            case 2:
                {
                    //| jmp <2
                    dasm_put(Dst, 87);
#line 183 "compiler/assembly/assembly.dasc"
                    printf("<2 \n");
                    break;
                }
            case 3:
                {
                    //| jmp <3
                    dasm_put(Dst, 92);
#line 189 "compiler/assembly/assembly.dasc"
                    printf("<3 \n");
                    break;
                }
            case 4:
                {
                    //| jmp <4
                    dasm_put(Dst, 97);
#line 195 "compiler/assembly/assembly.dasc"
                    printf("<4 \n");
                    break;
                }
            case 5:
                {
                    //| jmp <5
                    dasm_put(Dst, 102);
#line 201 "compiler/assembly/assembly.dasc"
                    printf("<5 \n");
                    break;
                }
            case 6:
                {
                    //| jmp <6
                    dasm_put(Dst, 107);
#line 207 "compiler/assembly/assembly.dasc"
                    printf("<6 \n");
                    break;
                }
            case 7:
                {
                    //| jmp <7
                    dasm_put(Dst, 112);
#line 213 "compiler/assembly/assembly.dasc"
                    printf("<7 \n");
                    break;
                }
            case 8:
                {
                    //| jmp <8
                    dasm_put(Dst, 117);
#line 219 "compiler/assembly/assembly.dasc"
                    printf("<8 \n");
                    break;
                }
            case 9:
                {
                    //| jmp <9
                    dasm_put(Dst, 122);
#line 225 "compiler/assembly/assembly.dasc"
                    printf("<9 \n");
                    break;
                }
        }
}


void Assembly::conditionalJumpForwardTo(int labelNumber, bool condition){
    if(condition == false){
        if(labelNumber == 1  && operator_==EQ)
            //| jne  >1
            dasm_put(Dst, 127);
#line 236 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
            //| je  >1
            dasm_put(Dst, 132);
#line 238 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
            //| jbe  >1
            dasm_put(Dst, 137);
#line 240 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
            //| jae  >1
            dasm_put(Dst, 142);
#line 242 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
            //| jb  >1
            dasm_put(Dst, 147);
#line 244 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
            //| ja  >1
            dasm_put(Dst, 152);
#line 246 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
            //| jne  >2
            dasm_put(Dst, 157);
#line 248 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
            //| je  >2
            dasm_put(Dst, 162);
#line 250 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
            //| jbe  >2
            dasm_put(Dst, 167);
#line 252 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
            //| jae  >2
            dasm_put(Dst, 172);
#line 254 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
            //| jb  >2
            dasm_put(Dst, 177);
#line 256 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
            //| ja  >2
            dasm_put(Dst, 182);
#line 258 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
            //| jne  >3
            dasm_put(Dst, 187);
#line 260 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
            //| je  >3
            dasm_put(Dst, 192);
#line 262 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
            //| jbe  >3
            dasm_put(Dst, 197);
#line 264 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
            //| jae  >3
            dasm_put(Dst, 202);
#line 266 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
            //| jb  >3
            dasm_put(Dst, 207);
#line 268 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
            //| ja  >3
            dasm_put(Dst, 212);
#line 270 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
            //| jne  >4
            dasm_put(Dst, 217);
#line 272 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
            //| je  >4
            dasm_put(Dst, 222);
#line 274 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
            //| jbe  >4
            dasm_put(Dst, 227);
#line 276 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
            //| jae  >4
            dasm_put(Dst, 232);
#line 278 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
            //| jb  >4
            dasm_put(Dst, 237);
#line 280 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
            //| ja  >4
            dasm_put(Dst, 242);
#line 282 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
            //| jne  >5
            dasm_put(Dst, 247);
#line 284 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
            //| je  >5
            dasm_put(Dst, 252);
#line 286 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
            //| jbe  >5
            dasm_put(Dst, 257);
#line 288 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
            //| jae  >5
            dasm_put(Dst, 262);
#line 290 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
            //| jb  >5
            dasm_put(Dst, 267);
#line 292 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
            //| ja  >5
            dasm_put(Dst, 272);
#line 294 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
            //| jne  >6
            dasm_put(Dst, 277);
#line 296 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
            //| je  >6
            dasm_put(Dst, 282);
#line 298 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
            //| jbe  >6
            dasm_put(Dst, 287);
#line 300 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
            //| jae  >6
            dasm_put(Dst, 292);
#line 302 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
            //| jb  >6
            dasm_put(Dst, 297);
#line 304 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
            //| ja  >6
            dasm_put(Dst, 302);
#line 306 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
            //| jne  >7
            dasm_put(Dst, 307);
#line 308 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
            //| je  >7
            dasm_put(Dst, 312);
#line 310 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
            //| jbe  >7
            dasm_put(Dst, 317);
#line 312 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
            //| jae  >7
            dasm_put(Dst, 322);
#line 314 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
            //| jb  >7
            dasm_put(Dst, 327);
#line 316 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
            //| ja  >7
            dasm_put(Dst, 332);
#line 318 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
            //| jne  >8
            dasm_put(Dst, 337);
#line 320 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
            //| je  >8
            dasm_put(Dst, 342);
#line 322 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
            //| jbe  >8
            dasm_put(Dst, 347);
#line 324 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
            //| jae  >8
            dasm_put(Dst, 352);
#line 326 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
            //| jb  >8
            dasm_put(Dst, 357);
#line 328 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
            //| ja  >8
            dasm_put(Dst, 362);
#line 330 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
            //| jne  >9
            dasm_put(Dst, 367);
#line 332 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
            //| je  >9
            dasm_put(Dst, 372);
#line 334 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
            //| jbe  >9
            dasm_put(Dst, 377);
#line 336 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
            //| jae  >9
            dasm_put(Dst, 382);
#line 338 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
            //| jb  >9
            dasm_put(Dst, 387);
#line 340 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
            //| ja  >9
            dasm_put(Dst, 392);
#line 342 "compiler/assembly/assembly.dasc"
    }
    else if(condition == true){
        if(labelNumber == 1  && operator_==EQ) 
            //| je  >1
            dasm_put(Dst, 132);
#line 346 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE) 
            //| jne  >1
            dasm_put(Dst, 127);
#line 348 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT) 
            //| ja  >1
            dasm_put(Dst, 152);
#line 350 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jb  >1
			 dasm_put(Dst, 147);
#line 352 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jge  >1
			 dasm_put(Dst, 397);
#line 354 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| jbe  >1
			 dasm_put(Dst, 137);
#line 356 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| je  >2
			 dasm_put(Dst, 162);
#line 358 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| jne  >2
			 dasm_put(Dst, 157);
#line 360 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| ja  >2
			 dasm_put(Dst, 182);
#line 362 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jb  >2
			 dasm_put(Dst, 177);
#line 364 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jge  >2
			 dasm_put(Dst, 402);
#line 366 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| jbe  >2
			 dasm_put(Dst, 167);
#line 368 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| je  >3
			 dasm_put(Dst, 192);
#line 370 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| jne  >3
			 dasm_put(Dst, 187);
#line 372 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| ja  >3
			 dasm_put(Dst, 212);
#line 374 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jb  >3
			 dasm_put(Dst, 207);
#line 376 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jge  >3
			 dasm_put(Dst, 407);
#line 378 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| jbe  >3
			 dasm_put(Dst, 197);
#line 380 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| je  >4
			 dasm_put(Dst, 222);
#line 382 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| jne  >4
			 dasm_put(Dst, 217);
#line 384 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| ja  >4
			 dasm_put(Dst, 242);
#line 386 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jb  >4
			 dasm_put(Dst, 237);
#line 388 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jge  >4
			 dasm_put(Dst, 412);
#line 390 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| jbe  >4
			 dasm_put(Dst, 227);
#line 392 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| je  >5
			 dasm_put(Dst, 252);
#line 394 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| jne  >5
			 dasm_put(Dst, 247);
#line 396 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| ja  >5
			 dasm_put(Dst, 272);
#line 398 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jb  >5
			 dasm_put(Dst, 267);
#line 400 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jge  >5
			 dasm_put(Dst, 417);
#line 402 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| jbe  >5
			 dasm_put(Dst, 257);
#line 404 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| je  >6
			 dasm_put(Dst, 282);
#line 406 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| jne  >6
			 dasm_put(Dst, 277);
#line 408 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| ja  >6
			 dasm_put(Dst, 302);
#line 410 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jb  >6
			 dasm_put(Dst, 297);
#line 412 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jge  >6
			 dasm_put(Dst, 422);
#line 414 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| jbe  >6
			 dasm_put(Dst, 287);
#line 416 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| je  >7
			 dasm_put(Dst, 312);
#line 418 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| jne  >7
			 dasm_put(Dst, 307);
#line 420 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| ja  >7
			 dasm_put(Dst, 332);
#line 422 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jb  >7
			 dasm_put(Dst, 327);
#line 424 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jge  >7
			 dasm_put(Dst, 427);
#line 426 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| jbe  >7
			 dasm_put(Dst, 317);
#line 428 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| je  >8
			 dasm_put(Dst, 342);
#line 430 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| jne  >8
			 dasm_put(Dst, 337);
#line 432 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| ja  >8
			 dasm_put(Dst, 362);
#line 434 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jb  >8
			 dasm_put(Dst, 357);
#line 436 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jge  >8
			 dasm_put(Dst, 432);
#line 438 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| jbe  >8
			 dasm_put(Dst, 347);
#line 440 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| je  >9
			 dasm_put(Dst, 372);
#line 442 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| jne  >9
			 dasm_put(Dst, 367);
#line 444 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| ja  >9
			 dasm_put(Dst, 392);
#line 446 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jb  >9
			 dasm_put(Dst, 387);
#line 448 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jge  >9
			 dasm_put(Dst, 437);
#line 450 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| jbe  >9
			 dasm_put(Dst, 377);
#line 452 "compiler/assembly/assembly.dasc"
        }
        
        if(condition == false){
                if(labelNumber == 1  && operator_==EQ) printf("jne  >1\n");
                else if(labelNumber == 1 && operator_==NE) printf("je  >1\n");
                else if(labelNumber == 1 && operator_==GT) printf("jbe  >1\n");
                else if(labelNumber == 1 && operator_==LT) printf("jae  >1\n");
                else if(labelNumber == 1 && operator_==GTE) printf("jb  >1\n");
                else if(labelNumber == 1 && operator_==LTE) printf("ja  >1\n");
                else if(labelNumber == 2  && operator_==EQ) printf("jne  >2\n");
                else if(labelNumber == 2 && operator_==NE) printf("je  >2\n");
                else if(labelNumber == 2 && operator_==GT) printf("jbe  >2\n");
                else if(labelNumber == 2 && operator_==LT) printf("jae  >2\n");
                else if(labelNumber == 2 && operator_==GTE) printf("jb  >2\n");
                else if(labelNumber == 2 && operator_==LTE) printf("ja  >2\n");
                else if(labelNumber == 3  && operator_==EQ) printf("jne  >3\n");
                else if(labelNumber == 3 && operator_==NE) printf("je  >3\n");
                else if(labelNumber == 3 && operator_==GT) printf("jbe  >3\n");
                else if(labelNumber == 3 && operator_==LT) printf("jae  >3\n");
                else if(labelNumber == 3 && operator_==GTE) printf("jb  >3\n");
                else if(labelNumber == 3 && operator_==LTE) printf("ja  >3\n");
                else if(labelNumber == 4  && operator_==EQ) printf("jne  >4\n");
                else if(labelNumber == 4 && operator_==NE) printf("je  >4\n");
                else if(labelNumber == 4 && operator_==GT) printf("jbe  >4\n");
                else if(labelNumber == 4 && operator_==LT) printf("jae  >4\n");
                else if(labelNumber == 4 && operator_==GTE) printf("jb  >4\n");
                else if(labelNumber == 4 && operator_==LTE) printf("ja  >4\n");
                else if(labelNumber == 5  && operator_==EQ) printf("jne  >5\n");
                else if(labelNumber == 5 && operator_==NE) printf("je  >5\n");
                else if(labelNumber == 5 && operator_==GT) printf("jbe  >5\n");
                else if(labelNumber == 5 && operator_==LT) printf("jae  >5\n");
                else if(labelNumber == 5 && operator_==GTE) printf("jb  >5\n");
                else if(labelNumber == 5 && operator_==LTE) printf("ja  >5\n");
                else if(labelNumber == 6  && operator_==EQ) printf("jne  >6\n");
                else if(labelNumber == 6 && operator_==NE) printf("je  >6\n");
                else if(labelNumber == 6 && operator_==GT) printf("jbe  >6\n");
                else if(labelNumber == 6 && operator_==LT) printf("jae  >6\n");
                else if(labelNumber == 6 && operator_==GTE) printf("jb  >6\n");
                else if(labelNumber == 6 && operator_==LTE) printf("ja  >6\n");
                else if(labelNumber == 7  && operator_==EQ) printf("jne  >7\n");
                else if(labelNumber == 7 && operator_==NE) printf("je  >7\n");
                else if(labelNumber == 7 && operator_==GT) printf("jbe  >7\n");
                else if(labelNumber == 7 && operator_==LT) printf("jae  >7\n");
                else if(labelNumber == 7 && operator_==GTE) printf("jb  >7\n");
                else if(labelNumber == 7 && operator_==LTE) printf("ja  >7\n");
                else if(labelNumber == 8  && operator_==EQ) printf("jne  >8\n");
                else if(labelNumber == 8 && operator_==NE) printf("je  >8\n");
                else if(labelNumber == 8 && operator_==GT) printf("jbe  >8\n");
                else if(labelNumber == 8 && operator_==LT) printf("jae  >8\n");
                else if(labelNumber == 8 && operator_==GTE) printf("jb  >8\n");
                else if(labelNumber == 8 && operator_==LTE) printf("ja  >8\n");
                else if(labelNumber == 9  && operator_==EQ) printf("jne  >9\n");
                else if(labelNumber == 9 && operator_==NE) printf("je  >9\n");
                else if(labelNumber == 9 && operator_==GT) printf("jbe  >9\n");
                else if(labelNumber == 9 && operator_==LT) printf("jae  >9\n");
                else if(labelNumber == 9 && operator_==GTE) printf("jb  >9\n");
                else if(labelNumber == 9 && operator_==LTE) printf("ja  >9\n");
            }else if(condition == true){
                if(labelNumber == 1  && operator_==EQ) printf("je  >1\n");
                else if(labelNumber == 1 && operator_==NE) printf("jne  >1\n");
                else if(labelNumber == 1 && operator_==GT) printf("ja  >1\n");
                else if(labelNumber == 1 && operator_==LT) printf("jb  >1\n");
                else if(labelNumber == 1 && operator_==GTE) printf("jge  >1\n");
                else if(labelNumber == 1 && operator_==LTE) printf("jbe  >1\n");
                else if(labelNumber == 2  && operator_==EQ) printf("je  >2\n");
                else if(labelNumber == 2 && operator_==NE) printf("jne  >2\n");
                else if(labelNumber == 2 && operator_==GT) printf("ja  >2\n");
                else if(labelNumber == 2 && operator_==LT) printf("jb  >2\n");
                else if(labelNumber == 2 && operator_==GTE) printf("jge  >2\n");
                else if(labelNumber == 2 && operator_==LTE) printf("jbe  >2\n");
                else if(labelNumber == 3  && operator_==EQ) printf("je  >3\n");
                else if(labelNumber == 3 && operator_==NE) printf("jne  >3\n");
                else if(labelNumber == 3 && operator_==GT) printf("ja  >3\n");
                else if(labelNumber == 3 && operator_==LT) printf("jb  >3\n");
                else if(labelNumber == 3 && operator_==GTE) printf("jge  >3\n");
                else if(labelNumber == 3 && operator_==LTE) printf("jbe  >3\n");
                else if(labelNumber == 4  && operator_==EQ) printf("je  >4\n");
                else if(labelNumber == 4 && operator_==NE) printf("jne  >4\n");
                else if(labelNumber == 4 && operator_==GT) printf("ja  >4\n");
                else if(labelNumber == 4 && operator_==LT) printf("jb  >4\n");
                else if(labelNumber == 4 && operator_==GTE) printf("jge  >4\n");
                else if(labelNumber == 4 && operator_==LTE) printf("jbe  >4\n");
                else if(labelNumber == 5  && operator_==EQ) printf("je  >5\n");
                else if(labelNumber == 5 && operator_==NE) printf("jne  >5\n");
                else if(labelNumber == 5 && operator_==GT) printf("ja  >5\n");
                else if(labelNumber == 5 && operator_==LT) printf("jb  >5\n");
                else if(labelNumber == 5 && operator_==GTE) printf("jge  >5\n");
                else if(labelNumber == 5 && operator_==LTE) printf("jbe  >5\n");
                else if(labelNumber == 6  && operator_==EQ) printf("je  >6\n");
                else if(labelNumber == 6 && operator_==NE) printf("jne  >6\n");
                else if(labelNumber == 6 && operator_==GT) printf("ja  >6\n");
                else if(labelNumber == 6 && operator_==LT) printf("jb  >6\n");
                else if(labelNumber == 6 && operator_==GTE) printf("jge  >6\n");
                else if(labelNumber == 6 && operator_==LTE) printf("jbe  >6\n");
                else if(labelNumber == 7  && operator_==EQ) printf("je  >7\n");
                else if(labelNumber == 7 && operator_==NE) printf("jne  >7\n");
                else if(labelNumber == 7 && operator_==GT) printf("ja  >7\n");
                else if(labelNumber == 7 && operator_==LT) printf("jb  >7\n");
                else if(labelNumber == 7 && operator_==GTE) printf("jge  >7\n");
                else if(labelNumber == 7 && operator_==LTE) printf("jbe  >7\n");
                else if(labelNumber == 8  && operator_==EQ) printf("je  >8\n");
                else if(labelNumber == 8 && operator_==NE) printf("jne  >8\n");
                else if(labelNumber == 8 && operator_==GT) printf("ja  >8\n");
                else if(labelNumber == 8 && operator_==LT) printf("jb  >8\n");
                else if(labelNumber == 8 && operator_==GTE) printf("jge  >8\n");
                else if(labelNumber == 8 && operator_==LTE) printf("jbe  >8\n");
                else if(labelNumber == 9  && operator_==EQ) printf("je  >9\n");
                else if(labelNumber == 9 && operator_==NE) printf("jne  >9\n");
                else if(labelNumber == 9 && operator_==GT) printf("ja  >9\n");
                else if(labelNumber == 9 && operator_==LT) printf("jb  >9\n");
                else if(labelNumber == 9 && operator_==GTE) printf("jge  >9\n");
                else if(labelNumber == 9 && operator_==LTE) printf("jbe  >9\n");
                }
}

void Assembly::conditionalJumpBackwardTo(int labelNumber, bool condition){
    if(condition == false){
        if(labelNumber == 1  && operator_==EQ)
			 //| jne  <1
			 dasm_put(Dst, 442);
#line 571 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
			 //| je  <1
			 dasm_put(Dst, 447);
#line 573 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
			 //| jbe  <1
			 dasm_put(Dst, 452);
#line 575 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jae  <1
			 dasm_put(Dst, 457);
#line 577 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jb  <1
			 dasm_put(Dst, 462);
#line 579 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| ja  <1
			 dasm_put(Dst, 467);
#line 581 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| jne  <2
			 dasm_put(Dst, 472);
#line 583 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| je  <2
			 dasm_put(Dst, 477);
#line 585 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| jbe  <2
			 dasm_put(Dst, 482);
#line 587 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jae  <2
			 dasm_put(Dst, 487);
#line 589 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jb  <2
			 dasm_put(Dst, 492);
#line 591 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| ja  <2
			 dasm_put(Dst, 497);
#line 593 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| jne  <3
			 dasm_put(Dst, 502);
#line 595 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| je  <3
			 dasm_put(Dst, 507);
#line 597 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| jbe  <3
			 dasm_put(Dst, 512);
#line 599 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jae  <3
			 dasm_put(Dst, 517);
#line 601 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jb  <3
			 dasm_put(Dst, 522);
#line 603 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| ja  <3
			 dasm_put(Dst, 527);
#line 605 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| jne  <4
			 dasm_put(Dst, 532);
#line 607 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| je  <4
			 dasm_put(Dst, 537);
#line 609 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| jbe  <4
			 dasm_put(Dst, 542);
#line 611 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jae  <4
			 dasm_put(Dst, 547);
#line 613 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jb  <4
			 dasm_put(Dst, 552);
#line 615 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| ja  <4
			 dasm_put(Dst, 557);
#line 617 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| jne  <5
			 dasm_put(Dst, 562);
#line 619 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| je  <5
			 dasm_put(Dst, 567);
#line 621 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| jbe  <5
			 dasm_put(Dst, 572);
#line 623 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jae  <5
			 dasm_put(Dst, 577);
#line 625 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jb  <5
			 dasm_put(Dst, 582);
#line 627 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| ja  <5
			 dasm_put(Dst, 587);
#line 629 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| jne  <6
			 dasm_put(Dst, 592);
#line 631 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| je  <6
			 dasm_put(Dst, 597);
#line 633 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| jbe  <6
			 dasm_put(Dst, 602);
#line 635 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jae  <6
			 dasm_put(Dst, 607);
#line 637 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jb  <6
			 dasm_put(Dst, 612);
#line 639 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| ja  <6
			 dasm_put(Dst, 617);
#line 641 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| jne  <7
			 dasm_put(Dst, 622);
#line 643 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| je  <7
			 dasm_put(Dst, 627);
#line 645 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| jbe  <7
			 dasm_put(Dst, 632);
#line 647 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jae  <7
			 dasm_put(Dst, 637);
#line 649 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jb  <7
			 dasm_put(Dst, 642);
#line 651 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| ja  <7
			 dasm_put(Dst, 647);
#line 653 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| jne  <8
			 dasm_put(Dst, 652);
#line 655 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| je  <8
			 dasm_put(Dst, 657);
#line 657 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| jbe  <8
			 dasm_put(Dst, 662);
#line 659 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jae  <8
			 dasm_put(Dst, 667);
#line 661 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jb  <8
			 dasm_put(Dst, 672);
#line 663 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| ja  <8
			 dasm_put(Dst, 677);
#line 665 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| jne  <9
			 dasm_put(Dst, 682);
#line 667 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| je  <9
			 dasm_put(Dst, 687);
#line 669 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| jbe  <9
			 dasm_put(Dst, 692);
#line 671 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jae  <9
			 dasm_put(Dst, 697);
#line 673 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jb  <9
			 dasm_put(Dst, 702);
#line 675 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| ja  <9
			 dasm_put(Dst, 707);
#line 677 "compiler/assembly/assembly.dasc"
    } else if(condition == true) {
        if(labelNumber == 1  && operator_==EQ)
			 //| je  <1
			 dasm_put(Dst, 447);
#line 680 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
			 //| jne  <1
			 dasm_put(Dst, 442);
#line 682 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
			 //| ja  <1
			 dasm_put(Dst, 467);
#line 684 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jb  <1
			 dasm_put(Dst, 462);
#line 686 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jge  <1
			 dasm_put(Dst, 712);
#line 688 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| jbe  <1
			 dasm_put(Dst, 452);
#line 690 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| je  <2
			 dasm_put(Dst, 477);
#line 692 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| jne  <2
			 dasm_put(Dst, 472);
#line 694 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| ja  <2
			 dasm_put(Dst, 497);
#line 696 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jb  <2
			 dasm_put(Dst, 492);
#line 698 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jge  <2
			 dasm_put(Dst, 717);
#line 700 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| jbe  <2
			 dasm_put(Dst, 482);
#line 702 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| je  <3
			 dasm_put(Dst, 507);
#line 704 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| jne  <3
			 dasm_put(Dst, 502);
#line 706 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| ja  <3
			 dasm_put(Dst, 527);
#line 708 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jb  <3
			 dasm_put(Dst, 522);
#line 710 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jge  <3
			 dasm_put(Dst, 722);
#line 712 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| jbe  <3
			 dasm_put(Dst, 512);
#line 714 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| je  <4
			 dasm_put(Dst, 537);
#line 716 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| jne  <4
			 dasm_put(Dst, 532);
#line 718 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| ja  <4
			 dasm_put(Dst, 557);
#line 720 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jb  <4
			 dasm_put(Dst, 552);
#line 722 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jge  <4
			 dasm_put(Dst, 727);
#line 724 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| jbe  <4
			 dasm_put(Dst, 542);
#line 726 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| je  <5
			 dasm_put(Dst, 567);
#line 728 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| jne  <5
			 dasm_put(Dst, 562);
#line 730 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| ja  <5
			 dasm_put(Dst, 587);
#line 732 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jb  <5
			 dasm_put(Dst, 582);
#line 734 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jge  <5
			 dasm_put(Dst, 732);
#line 736 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| jbe  <5
			 dasm_put(Dst, 572);
#line 738 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| je  <6
			 dasm_put(Dst, 597);
#line 740 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| jne  <6
			 dasm_put(Dst, 592);
#line 742 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| ja  <6
			 dasm_put(Dst, 617);
#line 744 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jb  <6
			 dasm_put(Dst, 612);
#line 746 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jge  <6
			 dasm_put(Dst, 737);
#line 748 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| jbe  <6
			 dasm_put(Dst, 602);
#line 750 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| je  <7
			 dasm_put(Dst, 627);
#line 752 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| jne  <7
			 dasm_put(Dst, 622);
#line 754 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| ja  <7
			 dasm_put(Dst, 647);
#line 756 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jb  <7
			 dasm_put(Dst, 642);
#line 758 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jge  <7
			 dasm_put(Dst, 742);
#line 760 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| jbe  <7
			 dasm_put(Dst, 632);
#line 762 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| je  <8
			 dasm_put(Dst, 657);
#line 764 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| jne  <8
			 dasm_put(Dst, 652);
#line 766 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| ja  <8
			 dasm_put(Dst, 677);
#line 768 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jb  <8
			 dasm_put(Dst, 672);
#line 770 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jge  <8
			 dasm_put(Dst, 747);
#line 772 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| jbe  <8
			 dasm_put(Dst, 662);
#line 774 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| je  <9
			 dasm_put(Dst, 687);
#line 776 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| jne  <9
			 dasm_put(Dst, 682);
#line 778 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| ja  <9
			 dasm_put(Dst, 707);
#line 780 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jb  <9
			 dasm_put(Dst, 702);
#line 782 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jge  <9
			 dasm_put(Dst, 752);
#line 784 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| jbe  <9
			 dasm_put(Dst, 692);
#line 786 "compiler/assembly/assembly.dasc"
	}
}


void Assembly::compile(){

    switch(operator_){
        case IDENTITY:
            {
                double* result = (double*) malloc(sizeof(double));
                //| fstp qword [result]
                //| movlpd xmm0, qword [result]
                //| ret
                dasm_put(Dst, 757, result, result);
#line 799 "compiler/assembly/assembly.dasc"
                printf("fstp qword %f \n", *result);
                printf("movlpd xmm0, qword [%f] \n", *result);
                printf("ret \n");
               break;
           }
        case ADD:
            {
                //| faddp st1
                dasm_put(Dst, 769);
#line 807 "compiler/assembly/assembly.dasc"
                printf("faddp st1 \n");
                break;
            }
         case SUB:
            {
                //| fsubp st1
                dasm_put(Dst, 772);
#line 813 "compiler/assembly/assembly.dasc"
                printf("fsubp st1 \n");
                break;
            }
         case MUL:
            {
                //| fmulp st1
                dasm_put(Dst, 776);
#line 819 "compiler/assembly/assembly.dasc"
                printf("fmulp st1 \n");
                break;
            }
         case DIV:
            {
                //| fdivp st1
                dasm_put(Dst, 779);
#line 825 "compiler/assembly/assembly.dasc"
                printf("fdivp st1 \n");
                break;
            }
         case NEG:
            {
                //| fchs
                dasm_put(Dst, 783);
#line 831 "compiler/assembly/assembly.dasc"
                printf("fchs \n");
                break;
            }
         case SQRT:
            {
                //| fsqrt
                dasm_put(Dst, 786);
#line 837 "compiler/assembly/assembly.dasc"
                printf("fsqrt \n");
                break;
            }
         case POW:
            {
                printf("^: Operation not supported yet");
                exit(0);
            }
         case EQ:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 849 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case NE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 857 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case GT:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 865 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case LT:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 873 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case GTE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 881 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case LTE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 889 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
    }

    operator_ = EMPTY;
}

Assembly::~Assembly(){
    dasm_free(&d);
}


void* Assembly::linkAndEncode(){
  operator_ = IDENTITY;
  compile();
  size_t sz;
  void* buf;
  dasm_link(Dst, &sz);
  buf = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  dasm_encode(Dst, buf);
  mprotect(buf, sz, PROT_READ | PROT_EXEC);
  return buf;
}
