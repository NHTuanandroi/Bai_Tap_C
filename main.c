#include"stdio.h"
#include"stdint.h"

typedef enum{
    SHIRT          = 1 << 0,   //0b00000001
    PANT           = 1 << 1,   //0b00000010
    SKIRT          = 1 << 2,   //0b00000100
    DRESS          = 1 << 3,   //0b00001000
    RING           = 1 << 4,   //0b00010000
    BRACELET       = 1 << 5,   //0b00100000
    SHOES          = 1 << 6,   //0b01000000
    BAG            = 1 << 7    //0b10000000
}Personal_Item;

char *Array_items[] = {"SHIRT","SHORT","SKIRT","DRESS","RING","BRACELET","SHOES","BAG"};// tạo mảng các sản phẩm

void Add_Cart(uint8_t *Cart, Personal_Item Item_name){
    *Cart |= Item_name;
}// thêm các sản phẩm bằng cách bật bit

void Remove_From_Cart(uint8_t *Cart, Personal_Item Item_name){
    *Cart &= ~Item_name;
}

void CheckItems(uint8_t Cart,Personal_Item Item_name){
    for(int i = 0;i < 8; i++){

         if(Item_name & (1 << i))// lấy từng sản phẩm
        {
            if((Cart>>i) & 1) //  lấy từng bit trong sản phẩm đó
            /* (cart>>i) & 1 công thức này kiểm tra xem bit thứ i là 0 hay 1
                Nếu là 1 thì tồn tại sản phẩm
                0 thì không có sản phẩm */
            {
                printf("THE CART HAS : %s\n", Array_items[i]);
            }
            else
            {
                printf("THE CART DOESN'T HAS : %s\n", Array_items[i]);  
            }              
        }
    }

}

void show_Items(int8_t Cart){

    printf( "The Items in Cart : ");
    
    for(int i = 0; i < 8; i++)
    {
        if(Cart & (1 << i))
        {
            printf("%s ", Array_items[i]);
        }
    }
    
    printf("\n");

}

int main()
{
    int8_t Cart;
    Add_Cart(&Cart,SHIRT|SHOES|SKIRT|BAG); 
    printf("KIEM TRA SAN PHAM\n");
    CheckItems(Cart,SHIRT|SHOES|RING);
    show_Items(Cart); // show các sản phẳm trong giỏ
}