/*  
    This was a coding problem in CodeWars
    Kata Challenge. Solved it

    nextSmaller(21) == 12
    nextSmaller(531) == 513
    nextSmaller(2071) == 2017
    nextSmaller(9) == -1
    nextSmaller(111) == -1
    nextSmaller(135) == -1

*/



unsigned char digitlength(unsigned long long x) {
    unsigned char r =0;
    while(x>0) { x/=10;r++; }
    return r;
}

unsigned long long power(int x) {
    unsigned long long r = 1;
    while(x-->0) 
        r *= 10l;
    return r;
}

void swapdigit(unsigned long long *number, char x, char y) {

    if(x==y)
        return;
    x++;
    y++;
    unsigned long long number_x, number_y;
    number_x = *number%power(x)/power(x-1)*power(x-1);
    number_y = *number%power(y)/power(y-1)*power(y-1);
    *number -=(number_x + number_y);
    number_x= number_x/power(x-1)*power(y-1);
    number_y= number_y/power(y-1)*power(x-1);
    *number +=(number_x + number_y);
}


unsigned char getdigit(unsigned long long number, unsigned char x) {
    x++;
    unsigned char number_x;
    number_x = number%power(x)/power(x-1);
    return number_x;
}

unsigned long long nextSmaller(unsigned long long n){

    unsigned long long ul = n;

    unsigned char length = digitlength(ul);

    char hit = -1;
    char hitnext = 0;
    char lastgreater = -1;

    for(int i=0; i< length; i++)
        if(getdigit(ul,i) < getdigit(ul,i+1)) {
            /*printf("digit=%d at pos=%d\n",getdigit(ul,i+1),i+1);*/
            hit = i+1;
            for(i=hit-1; i>=0;i--) {
                if(getdigit(ul,hit) > getdigit(ul,i) && lastgreater <= getdigit(ul,i))
                    hitnext = i;
            }
            break;
        }


    if((hit != -1 && hitnext >0) || (hitnext==0 && getdigit(ul,0)!=0)) {
        if(getdigit(ul,hit) > getdigit(hitnext,hitnext)) {
            swapdigit(&ul,hit, hitnext);

            int cur = 0;
            while(cur<hit) {
                for(int i=cur+1;i<hit;i++)
                    if(getdigit(ul,cur)>getdigit(ul,i))
                        swapdigit(&ul,cur,i);

                cur++;
            }
        }
    }


  return ((ul<n) && (digitlength(ul)==length)) ? ul : -1;

}



