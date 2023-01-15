class RemoveFromBig : public Container
{
    public :
        virtual int remove(){
            int big;
            big = data[0];
            for(int i = 0; i < index; i++)
                if(data[i] > big){
                    big = data[i];
                }
            for(int i = 0; i < index; i++){
                if(data[i] == big){
                    for(int k = i; k < index -1;k++){
                        data[k] = data[k+1];
                    }
                    --index;
                    --i;
                }
            }
            return big;
        }
};
class RemoveFromSmall : public Container
{
    public:
        virtual int remove(){
            int small;
            small = data[0];
            for(int i = 0; i < index; i++)
                if(data[i] < small){
                    small = data[i];
                }
            for(int i = 0; i < index; i++){
                if(data[i] == small){
                    for(int k = i; k < index -1;k++){
                        data[k] = data[k+1];
                    }
                    --index;
                    --i;
                }
            }
            return small;
        }
};
