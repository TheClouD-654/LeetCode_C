int reverse(int x){
    int y=0, b=-2147483648, c=2147483647;
        while(x){
            if(y>c/10 || y<b/10){
                return 0;
            }
            else{
                y=y*10 +x%10;
                x=x/10;
            }
        }
        return y;
}