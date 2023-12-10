#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <iomanip>
#include <windows.h>
#include "pokemon.h"
#include "movement.h"

using namespace std;

void battle(Pokemon* mypk,Pokemon* mypk2, Movement mv, int opc);
bool validacion(char *abc);
void gotoxy(int x,int y);
void dibujarCuadro(int x1,int y1,int x2,int y2);
void movimientos();
void pokemon();

int main()
{
    Pokemon chorizard,pitochu,*ptr1=&chorizard,*ptr2=&pitochu;
    Movement fire,lightning,normal,poison,sleep,heal;
    int aux,opponentAttack;
    int opc=0,opc2=0;
    char myChar[50];

    srand (time(NULL));
    default_random_engine generator(time(NULL));
    uniform_int_distribution<int> distribution(50,100);

    for(int i=0;i<10;i++)
    aux=distribution(generator); ///El primer numero siempre es igual, así que así se hace completamente aleatorio

    fire.setPower(distribution(generator)); fire.setStatus(1);
    lightning.setPower(distribution(generator));lightning.setStatus(2);
    normal.setPower(distribution(generator));normal.setStatus(3);
    poison.setPower(distribution(generator));poison.setStatus(4);
    sleep.setPower(0);sleep.setStatus(5);
    heal.setPower(0);heal.setStatus(6);

    chorizard.setName("Charizard");
    pitochu.setName("Pikachu");
    chorizard.setTotalHealth(distribution(generator)+150);
    chorizard.setCurrentHealth(chorizard.getTotalHealth());
    pitochu.setTotalHealth(distribution(generator)+150);
    pitochu.setCurrentHealth(pitochu.getTotalHealth());
    chorizard.setAttack(distribution(generator)+25);
    pitochu.setAttack(distribution(generator)+25);
    chorizard.setDefense(distribution(generator)+25);
    pitochu.setDefense(distribution(generator)+25);
    chorizard.setSpeed(distribution(generator)+50);
    pitochu.setSpeed(distribution(generator)+50);
    chorizard.setStatus(6);
    pitochu.setStatus(6);
    chorizard.setTurnsAsleep(0);
    pitochu.setTurnsAsleep(0);


    system("mode con: cols=150 lines=40");      ///CAMBIAR EL TAMAÑO DE LA CONSOLA

    while(pitochu.getCurrentHealth()>0 and chorizard.getCurrentHealth()>0){
            system("cls");

    dibujarCuadro(1,0,148,39);
    pokemon();                                  ///DIBUJAR LOS POKEMON

    gotoxy(1,33);printf("%c",204);
    for (int i=2;i<148;i++){
		gotoxy(i,33); printf("%c",205); //SEGUNDA LINEA HORIZONTAL PARA LOS MOVIMIENTOS
    }
    gotoxy(148,33);printf("%c",185);


    gotoxy(70,28);printf("%c",201);
    for (int i=71;i<148;i++){
		gotoxy(i,28); printf("%c",205); //LINEA HORIZONTAL PARA LA VIDA
    }
    gotoxy(148,28);printf("%c",185);
    for (int i=29;i<34;i++){
		gotoxy(70,i); printf("%c",186); //LINEA VERTICAL PARA LA VIDA
    }
    gotoxy(70,33);printf("%c",202);

    gotoxy(75,30);cout<<"VIDA DE CHARIZARD: "<<chorizard.getCurrentHealth()<<" ";  //ESTO TIENE QUE ESTAR SIEMPRE EN PANTALLA
    gotoxy(75,31);cout<<"ESTADO DE CHARIZARD: "<<chorizard.getStatus()<<"  ";
    gotoxy(120,30);cout<<"VIDA DE PIKACHU: "<<pitochu.getCurrentHealth()<<"  ";
    gotoxy(120,31);cout<<"ESTADO DE PIKACHU: "<<pitochu.getStatus()<<"  ";


    gotoxy(7,37);cout<<"[1].Atacar      [2].Revisar estadisticas de monstruos       [3]. Ver informacion de movimientos                                                      ";
    gotoxy(5,35);cout<<"Escoja una opcion:                              ";
    cin>>myChar;
    if(!validacion(myChar)){
        gotoxy(5,35);cout<<"Por favor, ingrese un caracter valido                           ";
        Sleep(1000);
    }else{
        opc2=atoi(myChar);
        switch(opc2){

            case 1:{
    movimientos();
    gotoxy(5,35);cout<<"Ataque:                                                                                                         ";
    cin>>myChar;

    if(!validacion(myChar)){
        gotoxy(5,35);cout<<"Por favor, ingrese un caracter valido               ";
    }else{
        opc=atoi(myChar);

    if((chorizard.getSpeed()>pitochu.getSpeed()) or pitochu.getStatus()==2)     ///SI TU POKEMON ES MÁS RAPIDO ATACA PRIMERO
    {
        switch(opc){            ///FASE DE ATAQUE ALIADA
        case 1:
        battle(ptr1,ptr2,fire,opc);          ///Lanzallamas
        break;

        case 2:
        battle(ptr1,ptr2,lightning,opc);    ///Rayo
        break;

        case 3:
        battle(ptr1,ptr2,normal,opc);       ///Cabezazo
        break;

        case 4:
        battle(ptr1,ptr2,poison,opc);       ///Bomba lodo
        break;

        case 5:
        battle(ptr1,ptr2,sleep,opc);         ///Bostezo
        break;

        case 6:
        battle(ptr1,ptr2,heal,opc);       ///Curacion
        break;

    }

    gotoxy(75,30);cout<<"VIDA DE CHARIZARD: "<<chorizard.getCurrentHealth()<<" ";  //ESTO TIENE QUE ESTAR SIEMPRE EN PANTALLA
    gotoxy(75,31);cout<<"ESTADO DE CHARIZARD: "<<chorizard.getStatus()<<"  ";
    gotoxy(120,30);cout<<"VIDA DE PIKACHU: "<<pitochu.getCurrentHealth()<<"  ";
    gotoxy(120,31);cout<<"ESTADO DE PIKACHU: "<<pitochu.getStatus()<<"  ";

    opponentAttack=rand()%6+1;
    gotoxy(5,35);cout<<"Ataque del oponente: "<<opponentAttack<<endl<<endl;
    switch(opponentAttack){
     case 1:
        battle(ptr2,ptr1,fire,opponentAttack);          ///Lanzallamas
        break;

        case 2:
        battle(ptr2,ptr1,lightning,opponentAttack);    ///Rayo
        break;

        case 3:
        battle(ptr2,ptr1,normal,opponentAttack);       ///Cabezazo
        break;

        case 4:
        battle(ptr2,ptr1,poison,opponentAttack);       ///Bomba lodo
        break;

        case 5:
        battle(ptr2,ptr1,sleep,opponentAttack);         ///Bostezo
        break;

        case 6:
        battle(ptr2,ptr1,heal,opponentAttack);       ///Curacion
        break;

    }///DEL SWITCH
    }///DEL IF
        else                    ///SI TU POKEMON ES MÁS LENTO, ATACA DE SEGUNDO
    {
        opponentAttack=rand()%6+1;
    gotoxy(5,35);cout<<"Ataque del oponente: "<<opponentAttack;
    switch(opponentAttack){
     case 1:
        battle(ptr2,ptr1,fire,opponentAttack);          ///Lanzallamas
        break;

        case 2:
        battle(ptr2,ptr1,lightning,opponentAttack);    ///Rayo
        break;

        case 3:
        battle(ptr2,ptr1,normal,opponentAttack);       ///Cabezazo
        break;

        case 4:
        battle(ptr2,ptr1,poison,opponentAttack);       ///Bomba lodo
        break;

        case 5:
        battle(ptr2,ptr1,sleep,opponentAttack);         ///Bostezo
        break;

        case 6:
        battle(ptr2,ptr1,heal,opponentAttack);       ///Curacion
        break;

    }

    gotoxy(75,30);cout<<"VIDA DE CHARIZARD: "<<chorizard.getCurrentHealth()<<" ";  //DESPUES DE UN ATAQUE SE MUESTRA LA VIDA NUEVA
    gotoxy(75,31);cout<<"ESTADO DE CHARIZARD: "<<chorizard.getStatus()<<"  ";
    gotoxy(120,30);cout<<"VIDA DE PIKACHU: "<<pitochu.getCurrentHealth()<<"  ";
    gotoxy(120,31);cout<<"ESTADO DE PIKACHU: "<<pitochu.getStatus()<<"  ";

        switch(opc){            ///FASE DE ATAQUE ALIADA
        case 1:
        battle(ptr1,ptr2,fire,opc);          ///Lanzallamas
        break;

        case 2:
        battle(ptr1,ptr2,lightning,opc);    ///Rayo
        break;

        case 3:
        battle(ptr1,ptr2,normal,opc);       ///Cabezazo
        break;

        case 4:
        battle(ptr1,ptr2,poison,opc);       ///Bomba lodo
        break;

        case 5:
        battle(ptr1,ptr2,sleep,opc);         ///Bostezo
        break;

        case 6:
        battle(ptr1,ptr2,heal,opc);       ///Curacion
        break;

    } ///DEL SWITCH
    }///DEL ELSE

    }/// DE LA VALIDACION
    }break;

        case 2:{                    ///INFORMACION DE LOS POKEMON
        gotoxy(5,35);cout<<"CHARIZARD:      << Ataque: "<<chorizard.getAttack()<<"                  Defensa:  "<<chorizard.getDefense()<< " Velocidad:    "<<chorizard.getSpeed()<< " >>                            ";
        gotoxy(5,37);cout<<"Pikachu:           << Ataque: "<<pitochu.getAttack()<<"                   Defensa:    "<<pitochu.getDefense()<< " Velocidad:    "<<pitochu.getSpeed()<<" >>                          ";
        cin.ignore();
        cin.ignore();
        break;}

        case 3:{        ///INFORMACION DE LOS MOVIMIENTOS
        gotoxy(5,35);cout<<"<<Lanzallamas>>         Fuerza: "<<fire.getPower()<<"               Estado: "<<fire.getStatus()<<"                                                 ";
        gotoxy(5,37);cout<<"<<Rayo>>                Fuerza: "<<lightning.getPower()<<"          Estado: "<<lightning.getStatus()<<"                                            ";
        cin.ignore();
        cin.ignore();
        gotoxy(5,35);cout<<"<<Bomba lodo>>              Fuerza: "<<poison.getPower()<<"            Estado: "<<poison.getStatus()<<"                                            ";
        gotoxy(5,37);cout<<"<<Cabezazo>>                Fuerza: "<<normal.getPower()<<"            Estado: "<<normal.getStatus()<<"                                            ";
        cin.ignore();
        gotoxy(5,35);cout<<"<<Bostezo>> Fuerza: 0 Estado: "<<sleep.getStatus()<<"                                                                                              ";
        gotoxy(5,37);cout<<"<<Recuperacion>> Este movimiento te cura 50% de vida y te regresa a estado 0                                                                       " ;
        cin.ignore();
        break;
        }
    }


    }
}
if(chorizard.getCurrentHealth()<0)
    {gotoxy(5,35);cout<<"Perdiste                                                                                                                 "<<endl;}
    else
    {gotoxy(5,35);cout<<"Ganaste                                                                                                                        "<<endl;}

    delete(ptr1);delete(ptr2);
    }
///ESTA ES LA MAQUINA DE ESTADOS, ENTRAN LOS DOS POKEMON (PARA SABER SUS ESTADOS), EL MOVIMIENTO USADO (PARA CAMBIAR EL ESTADO) Y LA OPCION QUE ESCOGIÓ EL USUARIO

void battle(Pokemon* mypk,Pokemon* mypk2, Movement mv, int opc){   ///El primer pokemon es el que hace daño, el segundo el que lo recibe
                                                                ///SE VE EL ESTADO DEL PRIMER POKEMON Y SE LE DA UNO AL SEGUNDO EN BASE AL ATAQUE QUE RECIBE
    unsigned int damage=0;
    char myChar;
    int sub=0,ta;

    if(mypk->getTurnsAsleep()==0){

        if(opc!=5 && opc!=6){

    switch(mypk->getStatus()){

    case 1:                                     ///QUEMADO


    gotoxy(5,37);cout<<mypk->getName()<<" esta quemado, hara menos daño                                                          ";
    system("pause");
    damage=(mypk->getAttack()+10*(mv.getPower()/15)-mypk2->getDefense())*.80;   ///Formula de daño -20% QUEMADO
    sub=mypk2->getCurrentHealth()-damage;
    gotoxy(5,37);cout<<mypk->getName()<<" ataco haciendo: "<<damage<<" de daño                                                    ";
    system("pause");
    mypk2->setCurrentHealth(sub);
    break;

    case 2:
    damage=(mypk->getAttack()+10*(mv.getPower()/15)-mypk2->getDefense());   ///PARALIZADO
    sub=mypk2->getCurrentHealth()-damage;
    gotoxy(5,37);cout<<mypk->getName()<<" ataco haciendo: "<<damage<<" de daño                                                    ";
    system("pause");
    mypk2->setCurrentHealth(sub);
    break;

    case 3:
    mypk->setCurrentHealth(mypk->getCurrentHealth()*.85);///Pierde 15% de vida antes de atacar
    gotoxy(5,37);cout<<mypk->getName()<<" esta envenando, perdio vida                                                            ";
    system("pause");
    damage=(mypk->getAttack()+10*(mv.getPower()/15)-mypk2->getDefense());   ///ENVENANDO
    sub=mypk2->getCurrentHealth()-damage;
    mypk2->setCurrentHealth(sub);
    gotoxy(5,37);cout<<mypk->getName()<<" ataco haciendo: "<<damage<<" de daño                                                    ";
    system("pause");
    break;

    case 4:
        if(rand()%2+1==2){
    damage=(mypk->getAttack()+10*(mv.getPower()/15)-mypk2->getDefense());   ///CONFUNDIDO
    sub=mypk2->getCurrentHealth()-damage;
    gotoxy(5,37);cout<<mypk->getName()<<" ataco haciendo: "<<damage<<" de daño                                                   ";
    system("pause");
    mypk2->setCurrentHealth(sub);
        }else{
        gotoxy(5,37);cout<<mypk->getName()<<" esta confundido, se ataco a si mismo                                                            ";
        system("pause");
        mypk->setCurrentHealth(mypk->getCurrentHealth()*.90);           ///Pierde 10% de vida
        }
    break;

    case 6:                         ///Status normal
    damage=mypk->getAttack()+10*(mv.getPower()/15)-mypk2->getDefense();   ///Formula normal de daño Normal
    sub=mypk2->getCurrentHealth()-damage;
    gotoxy(5,37);cout<<mypk->getName()<<" ataco haciendo: "<<damage<<" de daño                                                   ";
    system("pause");
    mypk2->setCurrentHealth(sub);
    break;
    }
    mypk2->setStatus(mv.getStatus());
            }else{              ///Escogió curación o dormir al otro

            if(opc==5){
                ta=rand()%2+1;
                mypk2->setTurnsAsleep(ta);
                mypk2->setStatus(5);
                gotoxy(5,37);cout<<"Turnos dormido: "<<ta<<"                                                                  ";
                    system("pause");}

            if(opc==6){
                mypk->setCurrentHealth(mypk->getCurrentHealth()+mypk->getTotalHealth()/2);
                if(mypk->getCurrentHealth()>mypk->getTotalHealth())
                    {mypk->setCurrentHealth(mypk->getTotalHealth());}
                    mypk->setStatus(6);
                    gotoxy(5,37);cout<<mypk->getName()<<" recupero: "<<mypk->getTotalHealth()/2<<" puntos de vida                  ";
                system("pause");
            }
            }
    }else{
        gotoxy(5,37);cout<<mypk->getName()<<" esta dormido por: "<<mypk->getTurnsAsleep()<<" turnos                          ";
        system("pause");
        mypk->setTurnsAsleep(mypk->getTurnsAsleep()-1);
        }




}

void movimientos(){
gotoxy(5,37);
cout<<"[1].Lanzallamas           [2].Rayo        [3].Cabezazo        [4].Bomba lodo          [5].Bostezo         [6].Recuperacion"<<endl;

}

void pokemon(){
    gotoxy(2,7);printf("                 |`._         |\\ \n");
    gotoxy(2,8);printf("                 `   `.  .    | `.    |`.\ \n");
    gotoxy(2,9);printf("                  .    `.|`-. |   `-..'  \\\\            _,.-'\n");
    gotoxy(2,10);printf("                  '      `-. `.           \\\ /|   _,-'   / \n");
    gotoxy(2,11);printf("              .--..'        `._`           ` |.-'      / \n");
    gotoxy(2,12);printf("               \\   |                                  / \n");
    gotoxy(2,12+1);printf("            ,..'   '                                 / \n");
    gotoxy(2,14);printf("            `.                                      / \n");
    gotoxy(2,15);printf("            _`.---                                 /\  \n");
    gotoxy(2,16);printf("        _,-'               `.                 ,-  /\"-._\n");
    gotoxy(2,17);printf("      ,\"                   | `.             ,'|   `    `.\n");
    gotoxy(2,18);printf("    .'                     |   `.         .'  |    .     `.\n");
    gotoxy(2,19);printf("  ,'                       '   ()`.     ,'()  '    |       `.\n");
    gotoxy(2,20);printf("'-.                    |`.  `.....-'    -----' _   |         .\n");
    gotoxy(2,21);printf(" / ,   ________..'     '  `-._              _.'/   |         :\n");
    gotoxy(2,22);printf(" ` '-\"\" _,.--\"'         \\   | `\"+--......-+' //   j `\"--.. , '\n");
    gotoxy(2,23);printf("    `.'\"    .'           `. |   |     |   / //    .       ` '\n");
    gotoxy(2,24);printf("      `.   /               `'   |    j   /,.'     '\n");
    gotoxy(2,25);printf("        \\ /                  `-.|_   |_.-'       /\\\n");
    gotoxy(2,26);printf("         /                        `\"\"          .'  \\\n");
    gotoxy(2,27);printf("        j                                           .\n");
    gotoxy(2,28);printf("        |                                 _,        |\n");
    gotoxy(2,29);printf("        |             ,^._            _.-\"          '\n");
    gotoxy(2,30);printf("        |          _.'    `'\"\"`----`\"'   `._       '\n");
    gotoxy(2,31);printf("        j__     _,'                         `-.'-.\"`\n");
    gotoxy(2,32);printf("          ',-.,' ");


    gotoxy(90,1);printf("           ______\n");
    gotoxy(90,2);printf("       _.-\"______`._             ,.\n");
    gotoxy(90,3);printf("     ,\"_,\"'      `-.`._         /.|\n");
    gotoxy(90,4);printf("   ,',\"   ____      `-.`.___   // |\n");
    gotoxy(90,5);printf("  /.' ,-\"'    `-._     `.   | j.  |  /|\n");
    gotoxy(90,6);printf(" // .'   __...._  `\"--.. `. ' |   | ' '\n");
    gotoxy(90,7);printf("j/  _.-\"'       `._,.\"\".   |  |   |/ '\n");
    gotoxy(90,8);printf("|.-'                    `.'/| |   | /\n");
    gotoxy(90,9);printf("'                        '/ | |   |/\n");
    gotoxy(90,10);printf("                         /  ' '   '\n");
    gotoxy(90,11);printf("                   |.   ` .'/.   /\n");
    gotoxy(90,12);printf("                   | `. ,','.  ,'\n");
    gotoxy(90,13);printf("                   |   \\.' j.-'/\n");
    gotoxy(90,14);printf("                   '   '   '. /\n");
    gotoxy(90,15);printf("                  |          `\"-...__\n");
    gotoxy(90,16);printf("                  |             _..-'\n");
    gotoxy(90,17);printf("                 ,|'      __.-7'   _......____\n");
    gotoxy(90,18);printf("                . |    ,\"/   ,'`.'__........___`-...__ \n");
    gotoxy(90,19);printf("                 .    '-'_..' .-\"\"-._         `\"\"'-----`.");
    gotoxy(90,20);printf("                 |____.-','\" /      /`.._,\"\".            .");
    gotoxy(90,21);printf("              ,\"`| ,'   '   |      .,--. ;--|             ");
    gotoxy(90,22);printf("             |   '.| `-.|   `.     ||   /   '`---.....--\"'");
    gotoxy(90,23);printf("             '     `._  |     `+----`._;'.   `-..____..--'");
    gotoxy(90,24);printf("              `.    | \"'|__...-|,|       /     `.\n");
    gotoxy(90,25);printf("                |-..|`-.7    /   '      /   |  '|\n");
    gotoxy(90,26);printf("                ' |' `.||`--'    |      \\   | . |\n");
    gotoxy(90,27);printf("                        |        |       \\  ' | |\n");
    gotoxy(90,28);printf("                        `.      .'        .   ' '\n");
}


void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

//FUNCION QUE DIBUJA EL CUADRO
void dibujarCuadro(int x1,int y1,int x2,int y2){
	int i;

    for (i=x1;i<x2;i++){
		gotoxy(i,y1); printf("%c",205); //linea horizontal superior
		gotoxy(i,y2); printf("%c",205); //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); printf("%c",186); //linea vertical izquierda
		gotoxy(x2,i); printf("%c",186); //linea vertical derecha
	}

    gotoxy(x1,y1); printf("%c",201);
    gotoxy(x1,y2); printf("%c",200);
    gotoxy(x2,y1); printf("%c",187);
    gotoxy(x2,y2); printf("%c",188);
}



bool validacion(char *abc){
   bool isValid=false;
    if(int(*abc)>=48 && int(*abc)<=57){
    isValid=true;
}
return isValid;
}
