#include<iostream>
#include<string>

using namespace std;

class Encryptor
{
    bool incremental;
    int count;
    public:

    Encryptor()
    {
        incremental = true;
        count = 1;
    }

    Encryptor(bool inc, int count)
    {
        incremental = inc;
        this->count = count;
    }

    std::string operator()(std::string data)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if ((data[i] >= 'a' && data[i] <= 'z')
                    || (data[i] >= 'A' && data[i] <= 'Z'))
            {
                if (incremental)
                {
                    data[i] = data[i] + count;
                }
                else
                {
                    data[i] = data[i] - count;
                }
            }
        }
        return data;
    }
};



std::string buildCompleteMessage(std::string rawData, Encryptor encyptorFuncObj )
{
    // some header and footer to data to make it complete messag
    rawData="[HEADER]"+rawData+"[FooTER]";
    cout << "Header data " << rawData << endl;

    // Call the callBack provided i.e. function pointer to encrypt the
    rawData = encyptorFuncObj(rawData);

    return rawData;
}


/* 
 * Encryptor(true, 1);
 *
 *  is same as 
 *
 *  Encryptor tempObj;
 *  tempObj.operator(true, 1);
 *
 * */



int main() {
    //Encryptor e1(true, 1);
    std::string msg = buildCompleteMessage("SampleString", Encryptor(true, 1));
    std::cout << msg << std::endl;

    //Encryptor e2(true, 2);
    msg = buildCompleteMessage("SampleString", Encryptor(true, 2));
    std::cout << msg << std::endl;

    //Encryptor e3(false, 1);
    msg = buildCompleteMessage("SampleString", Encryptor(false, 1));
    std::cout << msg << std::endl;

    return 0;
}
