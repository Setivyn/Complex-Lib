#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Complex-Number.h"

//Create & Complete
ComplexNum* completeComplex(ComplexNum* arg)
{
    //Assume Numbers are always completed when entered or calculated on
    struct ComplexNum* temp = NULL;
    temp = (ComplexNum*)malloc(sizeof(ComplexNum));
    if ((arg->Mod == 0) && (arg->Re != 0))
    {
        temp->Re = arg->Re;
        temp->Im = arg->Im;
        temp->Mod = sqrt((arg->Re * arg->Re) + (arg->Im * arg->Im));
        temp->Arg = atan2(arg->Re,arg->Im); //atan2 Is WONDERFUL, returns radian pos, in Principal Argument.
    }
    else if((arg->Re == 0) && (arg->Mod != 0))
    {
        temp->Re = arg->Mod * cos(arg->Arg);
        temp->Im = arg->Mod * sin(arg->Arg);
        temp->Mod = arg->Mod;
        temp->Arg = arg->Arg;
    }
    else
    {
        temp->Re = 0;
        temp->Im = 0;
        temp->Mod = 0;
        temp->Arg = 0;
    }
    return temp;
}
//
//Standard Arithmetic Functions
ComplexNum* addC(ComplexNum* arg1, ComplexNum* arg2)
{
    struct ComplexNum* temp = NULL;
    temp = (ComplexNum*)malloc(sizeof(ComplexNum));
    temp->Re = arg1->Re + arg2->Re;
    temp->Im = arg1->Im + arg2->Im;
    return completeComplex(temp);
}

ComplexNum* multC(ComplexNum* arg1, ComplexNum* arg2)
{
    struct ComplexNum* temp = NULL;
    temp = (ComplexNum*)malloc(sizeof(ComplexNum));
    temp->Mod = arg1->Mod * arg2->Mod;
    temp->Arg = arg1->Arg + arg2->Arg;
    return completeComplex(temp);
}

ComplexNum* subC(ComplexNum* arg1, ComplexNum* arg2)
{
    struct ComplexNum* temp = NULL;
    temp = (ComplexNum*)malloc(sizeof(ComplexNum));
    temp->Re = arg1->Re - arg2->Re;
    temp->Im = arg1->Im - arg2->Im;
    return completeComplex(temp);
}

ComplexNum* divC(ComplexNum* arg1, ComplexNum* arg2)
{
    if (arg2->Mod == 0)
    {
        return -1;
    }
    struct ComplexNum* temp = NULL;
    temp = (ComplexNum*)malloc(sizeof(ComplexNum));
    temp->Mod = arg1->Mod / arg2->Mod;
    temp->Arg = arg1->Arg - arg2->Arg;
    return completeComplex(temp);
}

ComplexNum* recipC(ComplexNum* arg)
{
    if(arg->Mod == 0){return 0;}
    struct ComplexNum* temp = NULL;
    temp = (ComplexNum*)malloc(sizeof(ComplexNum));
    temp->Re = (arg->Re / arg->Mod);
    temp->Im = (-arg->Im / arg->Mod);
    return completeComplex(temp);
}

ComplexNum* complexConjugate(ComplexNum* arg)


{
    struct ComplexNum* temp = NULL;
    temp = (ComplexNum*)malloc(sizeof(ComplexNum));
    temp->Re = arg->Re;
    temp->Im = -arg->Im;
    return completeComplex(temp);
}

ComplexNum* Power(ComplexNum* base, double index)

{
    struct ComplexNum* temp;
    temp = (ComplexNum*)malloc(sizeof(ComplexNum));
    temp->Mod = pow(base->Mod, index);
    temp->Arg = base->Arg * index;
    return completeComplex(temp);
}
//
//Boolean Expressions (The Complex Plane is an unordered field, meaning one number being greater/less than another has no meaning.)
int equalC(ComplexNum* arg1, ComplexNum* arg2)

{
    if ((arg1->Re == arg2->Re)&&(arg1->Im == arg2->Im)) {return 1;}
    return 0;
}
