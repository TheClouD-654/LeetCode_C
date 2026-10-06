bool isPalindrome(int x) {
    long long temp=0, a;
    if(x<0){
        return (FALSE);
    }
    else{
        a=x;
    }
    while (x!=0){
        temp=temp*10+x%10;
        x=x/10;
    }
    if (temp==a){
        return(TRUE);
    }
    else{
        return(FALSE);
    }
}