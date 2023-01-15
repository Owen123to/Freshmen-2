void sort(int array[], int n)
{
 int a,b,temp;
 for(a=1;a<n;a++){
   for(b=0;b<n-a;b++){
     if(array[b]>array[b+1]){
       temp=array[b];
       array[b]=array[b+1];
       array[b+1]=temp;
     }
   }
 }
}
