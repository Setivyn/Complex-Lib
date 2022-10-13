struct ComplexNum
{
    double Re;
    double Im;
    double Mod;
    double Arg;
};
typedef struct ComplexNum ComplexNum; //because of course this works

extern ComplexNum* addC(ComplexNum*, ComplexNum*);