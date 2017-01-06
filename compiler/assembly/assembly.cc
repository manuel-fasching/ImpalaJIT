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
    printf("fstp qword [%f] \n", *container);
    return container;
}

void Assembly::addLocalLabel(int labelNumber) {
    switch(labelNumber) {
        case 1:
            {
                //| 1:
                dasm_put(Dst, 10);
#line 59 "compiler/assembly/assembly.dasc"
                printf("1: \n");
                break;
            }
        case 2:
            {
                //| 2:
                dasm_put(Dst, 13);
#line 65 "compiler/assembly/assembly.dasc"
                printf("2: \n");
                break;
            }
        case 3:
            {
                //| 3:
                dasm_put(Dst, 16);
#line 71 "compiler/assembly/assembly.dasc"
                printf("3: \n");
                break;
            }
        case 4:
            {
                //| 4:
                dasm_put(Dst, 19);
#line 77 "compiler/assembly/assembly.dasc"
                printf("4: \n");
                break;
            }
        case 5:
            {
                //| 5:
                dasm_put(Dst, 22);
#line 83 "compiler/assembly/assembly.dasc"
                printf("5: \n");
                break;
            }
        case 6:
            {
                //| 6:
                dasm_put(Dst, 25);
#line 89 "compiler/assembly/assembly.dasc"
                printf("6: \n");
                break;
            }
        case 7:
            {
                //| 7:
                dasm_put(Dst, 28);
#line 95 "compiler/assembly/assembly.dasc"
                printf("7: \n");
                break;
            }
        case 8:
            {
                //| 8:
                dasm_put(Dst, 31);
#line 101 "compiler/assembly/assembly.dasc"
                printf("8: \n");
                break;
            }
        case 9:
            {
                //| 9:
                dasm_put(Dst, 34);
#line 107 "compiler/assembly/assembly.dasc"
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
#line 118 "compiler/assembly/assembly.dasc"
                    printf(">1 \n");
                    break;
                }
            case 2:
                {
                    //| jmp >2
                    dasm_put(Dst, 42);
#line 124 "compiler/assembly/assembly.dasc"
                    printf(">2 \n");
                    break;
                }
            case 3:
                {
                    //| jmp >3
                    dasm_put(Dst, 47);
#line 130 "compiler/assembly/assembly.dasc"
                    printf(">3 \n");
                    break;
                }
            case 4:
                {
                    //| jmp >4
                    dasm_put(Dst, 52);
#line 136 "compiler/assembly/assembly.dasc"
                    printf(">4 \n");
                    break;
                }
            case 5:
                {
                    //| jmp >5
                    dasm_put(Dst, 57);
#line 142 "compiler/assembly/assembly.dasc"
                    printf(">5 \n");
                    break;
                }
            case 6:
                {
                    //| jmp >6
                    dasm_put(Dst, 62);
#line 148 "compiler/assembly/assembly.dasc"
                    printf(">6 \n");
                    break;
                }
            case 7:
                {
                    //| jmp >7
                    dasm_put(Dst, 67);
#line 154 "compiler/assembly/assembly.dasc"
                    printf(">7 \n");
                    break;
                }
            case 8:
                {
                    //| jmp >8
                    dasm_put(Dst, 72);
#line 160 "compiler/assembly/assembly.dasc"
                    printf(">8 \n");
                    break;
                }
            case 9:
                {
                    //| jmp >9
                    dasm_put(Dst, 77);
#line 166 "compiler/assembly/assembly.dasc"
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
#line 178 "compiler/assembly/assembly.dasc"
                    printf("<1 \n");
                    break;
                }
            case 2:
                {
                    //| jmp <2
                    dasm_put(Dst, 87);
#line 184 "compiler/assembly/assembly.dasc"
                    printf("<2 \n");
                    break;
                }
            case 3:
                {
                    //| jmp <3
                    dasm_put(Dst, 92);
#line 190 "compiler/assembly/assembly.dasc"
                    printf("<3 \n");
                    break;
                }
            case 4:
                {
                    //| jmp <4
                    dasm_put(Dst, 97);
#line 196 "compiler/assembly/assembly.dasc"
                    printf("<4 \n");
                    break;
                }
            case 5:
                {
                    //| jmp <5
                    dasm_put(Dst, 102);
#line 202 "compiler/assembly/assembly.dasc"
                    printf("<5 \n");
                    break;
                }
            case 6:
                {
                    //| jmp <6
                    dasm_put(Dst, 107);
#line 208 "compiler/assembly/assembly.dasc"
                    printf("<6 \n");
                    break;
                }
            case 7:
                {
                    //| jmp <7
                    dasm_put(Dst, 112);
#line 214 "compiler/assembly/assembly.dasc"
                    printf("<7 \n");
                    break;
                }
            case 8:
                {
                    //| jmp <8
                    dasm_put(Dst, 117);
#line 220 "compiler/assembly/assembly.dasc"
                    printf("<8 \n");
                    break;
                }
            case 9:
                {
                    //| jmp <9
                    dasm_put(Dst, 122);
#line 226 "compiler/assembly/assembly.dasc"
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
#line 237 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
            //| je  >1
            dasm_put(Dst, 132);
#line 239 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
            //| jbe  >1
            dasm_put(Dst, 137);
#line 241 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
            //| jae  >1
            dasm_put(Dst, 142);
#line 243 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
            //| jb  >1
            dasm_put(Dst, 147);
#line 245 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
            //| ja  >1
            dasm_put(Dst, 152);
#line 247 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
            //| jne  >2
            dasm_put(Dst, 157);
#line 249 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
            //| je  >2
            dasm_put(Dst, 162);
#line 251 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
            //| jbe  >2
            dasm_put(Dst, 167);
#line 253 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
            //| jae  >2
            dasm_put(Dst, 172);
#line 255 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
            //| jb  >2
            dasm_put(Dst, 177);
#line 257 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
            //| ja  >2
            dasm_put(Dst, 182);
#line 259 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
            //| jne  >3
            dasm_put(Dst, 187);
#line 261 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
            //| je  >3
            dasm_put(Dst, 192);
#line 263 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
            //| jbe  >3
            dasm_put(Dst, 197);
#line 265 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
            //| jae  >3
            dasm_put(Dst, 202);
#line 267 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
            //| jb  >3
            dasm_put(Dst, 207);
#line 269 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
            //| ja  >3
            dasm_put(Dst, 212);
#line 271 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
            //| jne  >4
            dasm_put(Dst, 217);
#line 273 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
            //| je  >4
            dasm_put(Dst, 222);
#line 275 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
            //| jbe  >4
            dasm_put(Dst, 227);
#line 277 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
            //| jae  >4
            dasm_put(Dst, 232);
#line 279 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
            //| jb  >4
            dasm_put(Dst, 237);
#line 281 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
            //| ja  >4
            dasm_put(Dst, 242);
#line 283 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
            //| jne  >5
            dasm_put(Dst, 247);
#line 285 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
            //| je  >5
            dasm_put(Dst, 252);
#line 287 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
            //| jbe  >5
            dasm_put(Dst, 257);
#line 289 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
            //| jae  >5
            dasm_put(Dst, 262);
#line 291 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
            //| jb  >5
            dasm_put(Dst, 267);
#line 293 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
            //| ja  >5
            dasm_put(Dst, 272);
#line 295 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
            //| jne  >6
            dasm_put(Dst, 277);
#line 297 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
            //| je  >6
            dasm_put(Dst, 282);
#line 299 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
            //| jbe  >6
            dasm_put(Dst, 287);
#line 301 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
            //| jae  >6
            dasm_put(Dst, 292);
#line 303 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
            //| jb  >6
            dasm_put(Dst, 297);
#line 305 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
            //| ja  >6
            dasm_put(Dst, 302);
#line 307 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
            //| jne  >7
            dasm_put(Dst, 307);
#line 309 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
            //| je  >7
            dasm_put(Dst, 312);
#line 311 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
            //| jbe  >7
            dasm_put(Dst, 317);
#line 313 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
            //| jae  >7
            dasm_put(Dst, 322);
#line 315 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
            //| jb  >7
            dasm_put(Dst, 327);
#line 317 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
            //| ja  >7
            dasm_put(Dst, 332);
#line 319 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
            //| jne  >8
            dasm_put(Dst, 337);
#line 321 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
            //| je  >8
            dasm_put(Dst, 342);
#line 323 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
            //| jbe  >8
            dasm_put(Dst, 347);
#line 325 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
            //| jae  >8
            dasm_put(Dst, 352);
#line 327 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
            //| jb  >8
            dasm_put(Dst, 357);
#line 329 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
            //| ja  >8
            dasm_put(Dst, 362);
#line 331 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
            //| jne  >9
            dasm_put(Dst, 367);
#line 333 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
            //| je  >9
            dasm_put(Dst, 372);
#line 335 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
            //| jbe  >9
            dasm_put(Dst, 377);
#line 337 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
            //| jae  >9
            dasm_put(Dst, 382);
#line 339 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
            //| jb  >9
            dasm_put(Dst, 387);
#line 341 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
            //| ja  >9
            dasm_put(Dst, 392);
#line 343 "compiler/assembly/assembly.dasc"
    }
    else if(condition == true){
        if(labelNumber == 1  && operator_==EQ) 
            //| je  >1
            dasm_put(Dst, 132);
#line 347 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE) 
            //| jne  >1
            dasm_put(Dst, 127);
#line 349 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT) 
            //| ja  >1
            dasm_put(Dst, 152);
#line 351 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jb  >1
			 dasm_put(Dst, 147);
#line 353 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jge  >1
			 dasm_put(Dst, 397);
#line 355 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| jbe  >1
			 dasm_put(Dst, 137);
#line 357 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| je  >2
			 dasm_put(Dst, 162);
#line 359 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| jne  >2
			 dasm_put(Dst, 157);
#line 361 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| ja  >2
			 dasm_put(Dst, 182);
#line 363 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jb  >2
			 dasm_put(Dst, 177);
#line 365 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jge  >2
			 dasm_put(Dst, 402);
#line 367 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| jbe  >2
			 dasm_put(Dst, 167);
#line 369 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| je  >3
			 dasm_put(Dst, 192);
#line 371 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| jne  >3
			 dasm_put(Dst, 187);
#line 373 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| ja  >3
			 dasm_put(Dst, 212);
#line 375 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jb  >3
			 dasm_put(Dst, 207);
#line 377 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jge  >3
			 dasm_put(Dst, 407);
#line 379 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| jbe  >3
			 dasm_put(Dst, 197);
#line 381 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| je  >4
			 dasm_put(Dst, 222);
#line 383 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| jne  >4
			 dasm_put(Dst, 217);
#line 385 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| ja  >4
			 dasm_put(Dst, 242);
#line 387 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jb  >4
			 dasm_put(Dst, 237);
#line 389 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jge  >4
			 dasm_put(Dst, 412);
#line 391 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| jbe  >4
			 dasm_put(Dst, 227);
#line 393 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| je  >5
			 dasm_put(Dst, 252);
#line 395 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| jne  >5
			 dasm_put(Dst, 247);
#line 397 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| ja  >5
			 dasm_put(Dst, 272);
#line 399 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jb  >5
			 dasm_put(Dst, 267);
#line 401 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jge  >5
			 dasm_put(Dst, 417);
#line 403 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| jbe  >5
			 dasm_put(Dst, 257);
#line 405 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| je  >6
			 dasm_put(Dst, 282);
#line 407 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| jne  >6
			 dasm_put(Dst, 277);
#line 409 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| ja  >6
			 dasm_put(Dst, 302);
#line 411 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jb  >6
			 dasm_put(Dst, 297);
#line 413 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jge  >6
			 dasm_put(Dst, 422);
#line 415 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| jbe  >6
			 dasm_put(Dst, 287);
#line 417 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| je  >7
			 dasm_put(Dst, 312);
#line 419 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| jne  >7
			 dasm_put(Dst, 307);
#line 421 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| ja  >7
			 dasm_put(Dst, 332);
#line 423 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jb  >7
			 dasm_put(Dst, 327);
#line 425 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jge  >7
			 dasm_put(Dst, 427);
#line 427 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| jbe  >7
			 dasm_put(Dst, 317);
#line 429 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| je  >8
			 dasm_put(Dst, 342);
#line 431 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| jne  >8
			 dasm_put(Dst, 337);
#line 433 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| ja  >8
			 dasm_put(Dst, 362);
#line 435 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jb  >8
			 dasm_put(Dst, 357);
#line 437 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jge  >8
			 dasm_put(Dst, 432);
#line 439 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| jbe  >8
			 dasm_put(Dst, 347);
#line 441 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| je  >9
			 dasm_put(Dst, 372);
#line 443 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| jne  >9
			 dasm_put(Dst, 367);
#line 445 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| ja  >9
			 dasm_put(Dst, 392);
#line 447 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jb  >9
			 dasm_put(Dst, 387);
#line 449 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jge  >9
			 dasm_put(Dst, 437);
#line 451 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| jbe  >9
			 dasm_put(Dst, 377);
#line 453 "compiler/assembly/assembly.dasc"
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
#line 572 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
			 //| je  <1
			 dasm_put(Dst, 447);
#line 574 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
			 //| jbe  <1
			 dasm_put(Dst, 452);
#line 576 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jae  <1
			 dasm_put(Dst, 457);
#line 578 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jb  <1
			 dasm_put(Dst, 462);
#line 580 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| ja  <1
			 dasm_put(Dst, 467);
#line 582 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| jne  <2
			 dasm_put(Dst, 472);
#line 584 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| je  <2
			 dasm_put(Dst, 477);
#line 586 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| jbe  <2
			 dasm_put(Dst, 482);
#line 588 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jae  <2
			 dasm_put(Dst, 487);
#line 590 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jb  <2
			 dasm_put(Dst, 492);
#line 592 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| ja  <2
			 dasm_put(Dst, 497);
#line 594 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| jne  <3
			 dasm_put(Dst, 502);
#line 596 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| je  <3
			 dasm_put(Dst, 507);
#line 598 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| jbe  <3
			 dasm_put(Dst, 512);
#line 600 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jae  <3
			 dasm_put(Dst, 517);
#line 602 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jb  <3
			 dasm_put(Dst, 522);
#line 604 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| ja  <3
			 dasm_put(Dst, 527);
#line 606 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| jne  <4
			 dasm_put(Dst, 532);
#line 608 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| je  <4
			 dasm_put(Dst, 537);
#line 610 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| jbe  <4
			 dasm_put(Dst, 542);
#line 612 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jae  <4
			 dasm_put(Dst, 547);
#line 614 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jb  <4
			 dasm_put(Dst, 552);
#line 616 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| ja  <4
			 dasm_put(Dst, 557);
#line 618 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| jne  <5
			 dasm_put(Dst, 562);
#line 620 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| je  <5
			 dasm_put(Dst, 567);
#line 622 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| jbe  <5
			 dasm_put(Dst, 572);
#line 624 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jae  <5
			 dasm_put(Dst, 577);
#line 626 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jb  <5
			 dasm_put(Dst, 582);
#line 628 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| ja  <5
			 dasm_put(Dst, 587);
#line 630 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| jne  <6
			 dasm_put(Dst, 592);
#line 632 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| je  <6
			 dasm_put(Dst, 597);
#line 634 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| jbe  <6
			 dasm_put(Dst, 602);
#line 636 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jae  <6
			 dasm_put(Dst, 607);
#line 638 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jb  <6
			 dasm_put(Dst, 612);
#line 640 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| ja  <6
			 dasm_put(Dst, 617);
#line 642 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| jne  <7
			 dasm_put(Dst, 622);
#line 644 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| je  <7
			 dasm_put(Dst, 627);
#line 646 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| jbe  <7
			 dasm_put(Dst, 632);
#line 648 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jae  <7
			 dasm_put(Dst, 637);
#line 650 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jb  <7
			 dasm_put(Dst, 642);
#line 652 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| ja  <7
			 dasm_put(Dst, 647);
#line 654 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| jne  <8
			 dasm_put(Dst, 652);
#line 656 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| je  <8
			 dasm_put(Dst, 657);
#line 658 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| jbe  <8
			 dasm_put(Dst, 662);
#line 660 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jae  <8
			 dasm_put(Dst, 667);
#line 662 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jb  <8
			 dasm_put(Dst, 672);
#line 664 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| ja  <8
			 dasm_put(Dst, 677);
#line 666 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| jne  <9
			 dasm_put(Dst, 682);
#line 668 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| je  <9
			 dasm_put(Dst, 687);
#line 670 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| jbe  <9
			 dasm_put(Dst, 692);
#line 672 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jae  <9
			 dasm_put(Dst, 697);
#line 674 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jb  <9
			 dasm_put(Dst, 702);
#line 676 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| ja  <9
			 dasm_put(Dst, 707);
#line 678 "compiler/assembly/assembly.dasc"
    } else if(condition == true) {
        if(labelNumber == 1  && operator_==EQ)
			 //| je  <1
			 dasm_put(Dst, 447);
#line 681 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==NE)
			 //| jne  <1
			 dasm_put(Dst, 442);
#line 683 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GT)
			 //| ja  <1
			 dasm_put(Dst, 467);
#line 685 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LT)
			 //| jb  <1
			 dasm_put(Dst, 462);
#line 687 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==GTE)
			 //| jge  <1
			 dasm_put(Dst, 712);
#line 689 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 1 && operator_==LTE)
			 //| jbe  <1
			 dasm_put(Dst, 452);
#line 691 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2  && operator_==EQ)
			 //| je  <2
			 dasm_put(Dst, 477);
#line 693 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==NE)
			 //| jne  <2
			 dasm_put(Dst, 472);
#line 695 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GT)
			 //| ja  <2
			 dasm_put(Dst, 497);
#line 697 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LT)
			 //| jb  <2
			 dasm_put(Dst, 492);
#line 699 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==GTE)
			 //| jge  <2
			 dasm_put(Dst, 717);
#line 701 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 2 && operator_==LTE)
			 //| jbe  <2
			 dasm_put(Dst, 482);
#line 703 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3  && operator_==EQ)
			 //| je  <3
			 dasm_put(Dst, 507);
#line 705 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==NE)
			 //| jne  <3
			 dasm_put(Dst, 502);
#line 707 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GT)
			 //| ja  <3
			 dasm_put(Dst, 527);
#line 709 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LT)
			 //| jb  <3
			 dasm_put(Dst, 522);
#line 711 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==GTE)
			 //| jge  <3
			 dasm_put(Dst, 722);
#line 713 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 3 && operator_==LTE)
			 //| jbe  <3
			 dasm_put(Dst, 512);
#line 715 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4  && operator_==EQ)
			 //| je  <4
			 dasm_put(Dst, 537);
#line 717 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==NE)
			 //| jne  <4
			 dasm_put(Dst, 532);
#line 719 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GT)
			 //| ja  <4
			 dasm_put(Dst, 557);
#line 721 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LT)
			 //| jb  <4
			 dasm_put(Dst, 552);
#line 723 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==GTE)
			 //| jge  <4
			 dasm_put(Dst, 727);
#line 725 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 4 && operator_==LTE)
			 //| jbe  <4
			 dasm_put(Dst, 542);
#line 727 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5  && operator_==EQ)
			 //| je  <5
			 dasm_put(Dst, 567);
#line 729 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==NE)
			 //| jne  <5
			 dasm_put(Dst, 562);
#line 731 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GT)
			 //| ja  <5
			 dasm_put(Dst, 587);
#line 733 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LT)
			 //| jb  <5
			 dasm_put(Dst, 582);
#line 735 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==GTE)
			 //| jge  <5
			 dasm_put(Dst, 732);
#line 737 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 5 && operator_==LTE)
			 //| jbe  <5
			 dasm_put(Dst, 572);
#line 739 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6  && operator_==EQ)
			 //| je  <6
			 dasm_put(Dst, 597);
#line 741 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==NE)
			 //| jne  <6
			 dasm_put(Dst, 592);
#line 743 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GT)
			 //| ja  <6
			 dasm_put(Dst, 617);
#line 745 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LT)
			 //| jb  <6
			 dasm_put(Dst, 612);
#line 747 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==GTE)
			 //| jge  <6
			 dasm_put(Dst, 737);
#line 749 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 6 && operator_==LTE)
			 //| jbe  <6
			 dasm_put(Dst, 602);
#line 751 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7  && operator_==EQ)
			 //| je  <7
			 dasm_put(Dst, 627);
#line 753 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==NE)
			 //| jne  <7
			 dasm_put(Dst, 622);
#line 755 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GT)
			 //| ja  <7
			 dasm_put(Dst, 647);
#line 757 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LT)
			 //| jb  <7
			 dasm_put(Dst, 642);
#line 759 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==GTE)
			 //| jge  <7
			 dasm_put(Dst, 742);
#line 761 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 7 && operator_==LTE)
			 //| jbe  <7
			 dasm_put(Dst, 632);
#line 763 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8  && operator_==EQ)
			 //| je  <8
			 dasm_put(Dst, 657);
#line 765 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==NE)
			 //| jne  <8
			 dasm_put(Dst, 652);
#line 767 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GT)
			 //| ja  <8
			 dasm_put(Dst, 677);
#line 769 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LT)
			 //| jb  <8
			 dasm_put(Dst, 672);
#line 771 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==GTE)
			 //| jge  <8
			 dasm_put(Dst, 747);
#line 773 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 8 && operator_==LTE)
			 //| jbe  <8
			 dasm_put(Dst, 662);
#line 775 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9  && operator_==EQ)
			 //| je  <9
			 dasm_put(Dst, 687);
#line 777 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==NE)
			 //| jne  <9
			 dasm_put(Dst, 682);
#line 779 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GT)
			 //| ja  <9
			 dasm_put(Dst, 707);
#line 781 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LT)
			 //| jb  <9
			 dasm_put(Dst, 702);
#line 783 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==GTE)
			 //| jge  <9
			 dasm_put(Dst, 752);
#line 785 "compiler/assembly/assembly.dasc"
        else if(labelNumber == 9 && operator_==LTE)
			 //| jbe  <9
			 dasm_put(Dst, 692);
#line 787 "compiler/assembly/assembly.dasc"
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
#line 800 "compiler/assembly/assembly.dasc"
                printf("fstp qword %f \n", *result);
                printf("movlpd xmm0, qword [%f] \n", *result);
                printf("ret \n");
               break;
           }
        case ADD:
            {
                //| faddp st1
                dasm_put(Dst, 769);
#line 808 "compiler/assembly/assembly.dasc"
                printf("faddp st1 \n");
                break;
            }
         case SUB:
            {
                //| fsubp st1
                dasm_put(Dst, 772);
#line 814 "compiler/assembly/assembly.dasc"
                printf("fsubp st1 \n");
                break;
            }
         case MUL:
            {
                //| fmulp st1
                dasm_put(Dst, 776);
#line 820 "compiler/assembly/assembly.dasc"
                printf("fmulp st1 \n");
                break;
            }
         case DIV:
            {
                //| fdivp st1
                dasm_put(Dst, 779);
#line 826 "compiler/assembly/assembly.dasc"
                printf("fdivp st1 \n");
                break;
            }
         case NEG:
            {
                //| fchs
                dasm_put(Dst, 783);
#line 832 "compiler/assembly/assembly.dasc"
                printf("fchs \n");
                break;
            }
         case SQRT:
            {
                //| fsqrt
                dasm_put(Dst, 786);
#line 838 "compiler/assembly/assembly.dasc"
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
#line 850 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case NE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 858 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case GT:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 866 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case LT:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 874 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case GTE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 882 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case LTE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 790);
#line 890 "compiler/assembly/assembly.dasc"
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
