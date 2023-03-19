#include <stdio.h>
#include <stdint.h>

uint8_t GIO_HANG;

typedef enum
{
    AO          = 1 <<0,  //0b00000001
    QUAN        = 1 << 1, //0b00000010
    VAY         = 1 << 2, //0b00000100
    DAM         = 1 << 3, //0b00001000
    NHAN        = 1 << 4, //0b00010000
    VONG_TAY    = 1 << 5, //0b00100000
    GIAY        = 1 << 6, //0b01000000
    TUI         = 1 << 7  //0b10000000
}DO_DUNG_CA_NHAN;

char *check(uint8_t position)
{
    switch(position)
    {
        case 0:
            return "AO";
            break;
        case 1:
            return "QUAN";
            break;
        case 2:
            return "VAY";
            break;
        case 3:
            return "DAM";
            break;
        case 4:
            return "NHAN";
            break;
        case 5:
            return "VONG_TAY";
            break;
        case 6:
            return "GIAY";
            break;
        case 7:
            return "TUI";
            break;
    }
}

void Them_Vao_Gio_Hang(uint8_t *gio_hang,DO_DUNG_CA_NHAN ten_do_dung)
{
    *gio_hang  |= ten_do_dung;
}

void Xoa_Khoi_Gio_Hang(uint8_t *gio_hang,DO_DUNG_CA_NHAN ten_do_dung)
{
    *gio_hang &= ~ ten_do_dung;
}

void Kiem_Tra_San_Pham(uint8_t *gio_hang,DO_DUNG_CA_NHAN ten_do_dung)
{
    int tontai = *gio_hang & ten_do_dung;
    int khongtontai = ten_do_dung &  ~tontai;

    for(uint8_t pos = 0; pos <= 7; pos ++)
    {
        if((tontai & (1 << pos)) != 0)
        {
            printf("%s - Co trong gio hang\n",check(pos));
        }
    }
    for(uint8_t pos = 0; pos <= 7; pos ++)
    {
        if((khongtontai & (1 << pos)) != 0)
        {
            printf("%s - Khong co trong gio hang\n",check(pos));
        }
    }

}
void Hien_Thi_Gio_Hang(uint8_t *gio_hang)
{
    printf("Gio hang gom co: \n");
    printf("STT \t TEN \n");
    uint8_t stt = 0;
    for(uint8_t pos = 0; pos <= 7; pos ++)
    {
        if((*gio_hang & (1 << pos)) != 0)
        {
            stt ++;
            printf("%d\t %s\n",stt,check(pos));
        }
    }
}
int main(int argc, char const *argv[])
{
    //0b01010001
    //0b11111110 ~AO
    //Ob01010000
    Them_Vao_Gio_Hang(&GIO_HANG, NHAN|AO|GIAY|VONG_TAY|GIAY);
    printf("\n");
    Hien_Thi_Gio_Hang(&GIO_HANG);

    Xoa_Khoi_Gio_Hang(&GIO_HANG, NHAN);
    printf("\n");
    Hien_Thi_Gio_Hang(&GIO_HANG);
    printf("\n");
    Kiem_Tra_San_Pham(&GIO_HANG, NHAN|VONG_TAY);
    return 0;
}