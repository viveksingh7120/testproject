
/* INI parser using map*/

#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<map>
using namespace std;
int main()
{
	int inLength, index, flag=0;
	char str[10000], key[500], value[500];
	string buffer_temp;
	/* Craete map */
	map < string, string > m;
	map < string, string >::iterator i;
	/* Open file */
	ifstream ifile;
	ifile.open("ParameterMapping.txt");
	if(!ifile)
	{
		cout<<"Error in opening file..!!";
		exit(0);
	}
	while(!ifile.eof())
    {
        if( getline(ifile,buffer_temp))
        {
        }
        long long index = 0;
        for(index=0;index<buffer_temp.size();index++)
        {
            str[index] = buffer_temp[index];
        }
        str[index] = '\0';
        inLength=strlen(str);
		if((str[0]>='A' && str[0]<='Z')||(str[0]>='a' && str[0]<='z')||(str[0]>='0' && str[0]<='9'))
		{
			int keylen=0, valuelen=0;
			for( index = 0; index < inLength; index ++ )
			{
				if( str[index] == '=')
				{
					++flag;
				}

			}
			if(flag == 0)
            {
                cout<<"File not in proper format4"<<endl;
                exit(0);
            }
			for( index = 0; str[index]!='='; index ++)
			{
				key[index] = str[index];
				++keylen;
			}
			key[index]='\0';

			keylen = keylen + 1;
			for( index = keylen; index < inLength; index++)
			{
				value[valuelen] = str[index];
				++valuelen;
			}
			value[valuelen]='\0';
			m[key] = value;
		}
    }
    ifile.close();
	//string h ="passthroughenabled             ";
	for( i = m.begin(); i != m.end(); i++ )
	{
            cout<< i -> first <<"  ";
            cout<< i -> second <<endl;
	}

	cout<<m["TERMINAL.SPWD1"];
}
