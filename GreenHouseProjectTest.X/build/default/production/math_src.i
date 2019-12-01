# 1 "math_src.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "math_src.c" 2
# 1 "./math_driver.h" 1



int modulus_func(int,int);
char incrementor(int,int,char);
char decrementor(int,int,char);
# 1 "math_src.c" 2




int modulus_func(int x,int y){
    x = x % y;
    return x;
}

char incrementor(int y,int x,char z){
     if(z == (x + '0')){
     y++;
     y =(modulus_func(y,10));
   }
     return y;
}

char decrementor(int w,int t ,char z){
     if(z == (t + '0')){

        w--;
        w = (modulus_func(w,10));
        }
     return w;
}
