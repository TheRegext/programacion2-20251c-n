#include <iostream>
#include "HttpClient.h"
using namespace std;

int main()
{
    HttpClient client;
    
    string res;
    
    res = client.get("https://links.theregext.com/");
    
    cout << res << endl;
    
    
    return 0;
}
