#include <iostream>
#include <iterator>
using namespace std;
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
int lvO(int local){
  int b = local%10;
  int level = local > 6 ? (b > 5 ? b : 5) : b;
  return level;
}
int sl(int levelO,int level){
  if(level > levelO){
    return 1;
  } else if(levelO == level){
    return 0;
  } else if(level < levelO){
    return -1;
  }
  return 0;
}
void checkLevel(int &level){
  if(level>10) level=10;
}
int damage1to5(int HP,int levelO,int &phoenixdown,int MaxHP,int codeEnvent, int &rescue){
  double baseDamage ;
  switch (codeEnvent) {
  case 1:
    baseDamage=1;
    break;
  case 2:
    baseDamage=1.5;
    break;
  case 3:
    baseDamage=4.5;
    break;
  case 4:
    baseDamage=7.5;
    break;
  case 5:
    baseDamage=9.5;
    break;
  }
  int damage=baseDamage*levelO*10;
  HP=HP-damage;
  if(HP <= 0 && phoenixdown == 0){
    rescue = 0;
    return HP;
  } else if(HP <= 0 && phoenixdown > 0){
    phoenixdown--;
    rescue = -1;
    return MaxHP;
  } else ;
  return HP;
}
void checkHP(int HP,int &rescue,int &phoenixdown,int &check,int MaxHP,int &counter){
  if(HP<0 && phoenixdown < 1) rescue =0;
  if(HP<0 && phoenixdown > 1) {
    phoenixdown--;
    check=0;
    HP=MaxHP;
    counter=0;
  }
}
int lowpeopleHP(int HP,int MaxHP,int check){
  if(check==1){
    if(HP < 5){
      HP=1;
      return HP;
    }else{
      HP=HP/5;
      return HP;
    }
  } else{
    HP=HP*5;
    if(HP>MaxHP){
      HP=MaxHP;
    }
    return HP;
  } 
}
void adventureToKoopa( int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue) {
  /*khai bao bien*/
  rescue=-1;
  int map[]={0,4,6,6,1,1};
  int local=1;
  int mapLength = sizeof(map) / sizeof(int);
  int levelO;
  int solo;
  int const MaxHP=HP;
  int check_people=0;
  int counter=0;

  while(rescue == -1){
    switch (map[local]) {
    case 0:
      rescue = 1;
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      levelO=lvO(local);
      solo = sl(levelO,level);
      if(solo == 1){
        level++;
        checkLevel(level);
      } else if (solo == 0){
        // Không làm gì cả
      } else if (solo == -1){
        HP = damage1to5(HP,levelO,phoenixdown,MaxHP,map[local],rescue);
        // cout<<HP;
        checkHP(HP,rescue,phoenixdown,check_people,MaxHP,counter);
      }
      break;
    case 6:
      levelO=lvO(local);
      solo = sl(levelO,level);
      if(solo == 1){
        level+=2;
        checkLevel(level);
      } else if (solo == 0){
        // Không làm gì cả
      } else if (solo == -1){
        check_people=1;
        counter=4;
        HP=lowpeopleHP(HP,MaxHP,check_people);
        if(remedy >= 1){
          check_people = 0;
          remedy--;
          counter=0;
          HP=HP*5;
        } else {
          if(HP<=0 && phoenixdown>0){
            check_people = 0;
            phoenixdown--;
            HP=MaxHP;
          } else if(HP<=0 && phoenixdown<0){
            rescue=0;
          }
        }
      }
    default:
      break;
    }
    // cout<<HP<<endl;
    local++;
    if(counter==1 && check_people==1){
      check_people=0;
      HP=HP*5;
      if(HP>MaxHP){
        HP=MaxHP;
      }
    } else if(counter!=0){
      counter--;
    };
    checkHP(HP,rescue,phoenixdown,check_people,MaxHP,counter);
    if(local==mapLength && rescue==-1) rescue=1;
  }
}
int main(int argc, char ** argv) {
    // string file_input(argv[1]);

    int HP, level, remedy, maidenkiss, phoenixdown, rescue;
    HP=998;
    level=1;
    remedy=0;
    maidenkiss=0;
    phoenixdown=0;

    adventureToKoopa( HP, level, remedy, maidenkiss, phoenixdown, rescue);
    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

    return 0;
}
