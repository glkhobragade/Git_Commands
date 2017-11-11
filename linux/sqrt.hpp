
extern "C"
{
   int sq(int num);
}
/*double PII  __attribute__ ((visibility ("hidden")));   ==> this will not allow to export the symbol outside of a library*/
double PII = 3.14;
