#include <iostream>
#include <string>
using namespace std;

std::string buildCompleteMessage(std::string rawData, std::string (* encrypterFunPtr)(std::string) )
{
    // some header and footer to data to make it complete messag
    rawData="[HEADER]"+rawData+"[FooTER]";
    cout << "Header data " << rawData << endl;

    // Call the callBack provided i.e. function pointer to encrypt the
    rawData = encrypterFunPtr(rawData);

    return rawData;
}


std::string encryptDataByLetterInc(std::string data)
{
    for(int i = 0; i < data.size(); i++)
    {
        if( (data[i] >= 'a' && data[i] <= 'z' ) || (data[i] >= 'A' && data[i] <= 'Z' ) )
            data[i]++;
    }
    return data;
}

int main()
{
    std::string encrypted = buildCompleteMessage("Thisisgood" ,&encryptDataByLetterInc);
    cout << "Encrypted data is " << encrypted << endl;
    return 0;
}
