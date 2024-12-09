//Ethan Ward 301040

int main()
{
    char buffer[] = "Hello World!";
    stringReverse(buffer);
    printf("%s", buffer);

    //char* secret = "DSZM" 
}

void stringReverse(char* str)
{
    int len;
    for(len=0; str[len]; ++len) {}
    char* tmp[len];

    // reverse the string
    for(int i=0; i<len; i++)
        tmp[i] = str[len-i];
    // copy the temp over to the original
    for(int i=0; i<len; i++)
        str[i] = tmp[i];
}

void cryptogramify(char* message)
{
    unsigned diff = 'z'-'a'; //'A' is 65 iirc, so this should be 29 maybe?
    for(int i=0; i<message[i]; i++)
        if(message[i] >= 'A' && message[i] <= 'Z')
            message[i] = message[i] + ('Z'-diff);
        else if(message[i] >= 'a' && message[i] <= 'z')
            message[i] = message[i] + ('z'-diff);
}

void pyramid(unsigned size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            if(j%2==i%2)
                if((((j+i)/2)+1)<j && j<(((j-i)/2)+1))
                    printf("*");
                else
                    print(" ");
            else
                if((((j+i)/2)+1)<j && j<(((j-i)/2)+1))
                    printf(" ");
                else
                    print("*");
        printf("\n");
    }
}