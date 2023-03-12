#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
//Function to check if input is larger or smaller than expect
void check_input(int & H_input, int & L_input, int & R_input, int & M_input, int & P_input){
    H_input = (H_input > 999) ? 999 : ((H_input < 1) ? 1 : H_input);
    L_input = ( L_input > 10) ? 10 : (( L_input < 0) ? 0 :  L_input);
    R_input = ( R_input > 99) ? 99 : (( R_input < 0) ? 0 :  R_input);
    M_input = ( M_input > 99) ? 99 : (( M_input < 0) ? 0 :  M_input);
    P_input = ( P_input > 99) ? 99 : (( P_input < 0) ? 0 :  P_input);
}
//Function to calculate sum of n1 numbers
int sum_n1 (int n1) {
    int max_2num = 99;
    int sum = 0;
    for (int k = 0; k < n1; k++){
        sum = sum + max_2num -2*k;
    }
    return sum;
}
// Function checking prime number
int prime_Number(int t){
    for (int i = 2; i <= sqrt(t); i ++) {
         if (t%i ==0) return 0;
    }
    return t > 1;
}
//Function increase HP to the nearest prime number
int prime_HP (int up_HP){
    int check;
    do 
    {
        up_HP++;
        check = prime_Number(up_HP);
    }
    while (!check);
    return up_HP;
}
//Function to determine the fibonacci
int fibo[17];
void fibonacci() {
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i <= 17; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}
//Function to determine the nearest fibo below
int fibo_HP (int n){
    fibonacci();
    int h;
    if (n == 1) return 1;
    for (int i = 1; i <= 17; i++){
        if (n > fibo[i] and n <= fibo[i+1]) {
            h =  fibo[i];
            break;
        }
        else continue;
    }
    return h;
}
//Function to store the mush ghost
void read_Event13  (int musharray[], string text, int & t) {
    ifstream File(text);
    File >> t;
    t = ( t > 100) ? 100 : t;
    for (int i= 0; i < t; i++) {
        File >> musharray[i];
        File.seekg(1,ios_base::cur);
    }
    File.close();
}
//Mush ghost case 1:
void find_Maxmin_index (int matr [], int n2, int & max, int & min) {
  int max_value =  matr[0];
  int min_value =  matr[0];
  for ( int i = 0; i < n2; i++) {
    if (matr[i] >= max_value) {
      max_value = matr[i];
      max = i;
    }
    if (matr[i] <= min_value) {
      min_value = matr[i];
      min = i;
    }
  }
}
void find_Maxmin_index_2 (int matr [], int n2, int & max, int & min) {
    int ind_min = 0;
    int ind_max = 0;
    int max_value =  matr[ind_max];
    int min_value =  matr[ind_min];
    for (int i = 0; i < n2; i ++) {
        if (matr [i] > max_value) {
            max_value = matr[i];
            max = i;
        }
        if (matr[i] < min_value) {
            min_value = matr[i];
            min = i;
        }
    }
}
//Function to analyze the mush ghost case 2
void check_Mountain_Up (int ar[],int n2 ,int & mtx, int & mti) {
  int count_up= 1;
  int count_down = 1;
  if (n2 > 1){
  for (int i = 0; i < n2 - 1; i ++) {
    if (ar[i+1]>ar[i]) {
        if (count_down > 1) {
        break;
        }
        else {
        mtx = ar[i+1];
        mti = i + 1;
        count_up++;
        }
    }
    else if (ar[i] > ar[i + 1]) {
        if (count_up > 1)
        {
            count_up ++;
            count_down ++;
        }
        else {
            mtx = ar[0];
            mti = 0;
            count_down++;
        }
    }
    else break;
    } 

    if (count_up == n2 or count_down == n2) {
        }
    else {
        mtx = -2;
        mti = -3;
        }
    }
    else if (n2 == 1){
        mtx = ar[0];
        mti = 0;
    }
    else {
        mtx = -2;
        mti = -3;
    }
}
//Case 3 event mush ghost
void case3_1(int arin[],int arout[],int a) {
    for (int i = 0; i <a; i++) {
        if (arin[i] < 0) {
        arout[i]=(17*arin[i]*(-1) + 9)%257;
        }
        else arout[i]=(17*arin[i] + 9)%257;
    }
}
//Case 4 mush ghost
void check_Case4_2 ( int a[] ,int n2 ,int& max_3x, int & max_3i) {
	if (n2 == 1) {
		max_3x = -5;	max_3i = -7;
	}
	else{
		if (a[0] > a[1]) {
			max_3x = a[1];
			max_3i = 1;
			if (n2 == 2) return;
			else {
				if (a[2] < a[0] and a[2] > a[1]) {
				max_3x = a[2];
				max_3i = 2;
			}
				else if (a[2] > a[0]) {
				max_3x = a[0];
				max_3i = 0;	
			}
				else {}
			}	
		}
		else if (a[0] < a[1]) {
			max_3x = a[0];
			max_3i = 0;	
			if (n2 == 2) return;
			else {
				if (a[2] > a[1]) {
					max_3x = a[1];
					max_3i = 1;
				}
				else if (a[2] > a[0] and a[2]< a[1]) {
					max_3x = a[2];
					max_3i = 2;
				}
				else {}
			}
		}
		else {
			max_3x = -5;	
			max_3i = -7;
			if (n2 == 2) return;
			else {
				if (a[2] < a[1]) {
					max_3x = a[2];
					max_3i = 2;
				}
				else if (a[2] >a[1]) {
					max_3x = a[0];
					max_3i = 0;
				}
				else {}
			}		
		}
	}
}

void get_Event18(string eventfile18, int n9, int & HP, int maxHP) {
    ifstream file(eventfile18);
    string line;
    getline (file, line);
    istringstream iss1 (line);
    iss1 >> line;
    while (getline(file, line)){
        int count_18_m = 0;
        int count_18_e  = 0;
        int count_18_r  = 0;
        int count_18_l = 0;
        int count_18_i = 0;
        int count_18_n = 0;
        int sum_merlin = 0;
        int merlin_check1 = line.find("merlin");
        int merlin_check2 = line.find("Merlin");
		if (merlin_check1 != -1 or merlin_check2 !=-1){
			HP = (HP+3 >maxHP) ? maxHP : HP +3; 
		}
		else {
			for (int i = 0; i < line.length(); i ++ ) {
				switch (line[i]) {
					case 'm':
					case 'M':
						if (count_18_m) break;
						count_18_m = 1;
						break;
					case 'e':
                    case 'E':
						if (count_18_e) break;
						count_18_e = 1;	
                        break;
					case 'r':
                    case 'R':
					    if (count_18_r) break;
						count_18_r = 1;	
                        break;
					case 'l':
                    case 'L':
						if (count_18_l) break;
						count_18_l = 1;	
                        break;	
					case 'i':
                    case 'I':
						if (count_18_i) break;
						count_18_i = 1;	
                        break;		
					case 'n':
                    case 'N':
						if (count_18_n) break;
						count_18_n = 1;	
                        break;				
				}
			}    
            sum_merlin = count_18_e + count_18_i + count_18_l + count_18_r + count_18_n + count_18_m;
            if (sum_merlin == 6) {
                HP = (HP+ 2 >maxHP) ? maxHP : HP +2; 
            }
		}   
    }
}

// Đọc ma trận từ sự kiện 19
void read_Event19 (int medicine[][500], string event19_package ,int & c1, int & r1) {
    ifstream file_event19(event19_package);
    file_event19 >> c1;
    file_event19 >> r1;
    for (int i = 1; i <= c1; i ++ ) {
        for (int j = 1; j <= r1; j ++) {
            file_event19 >> medicine[i][j];
        }
    }
    file_event19.close();
}
// Read when in 15 16 17
int get_Items (int t, int & Re, int & Ma, int & PH) {
    switch (t)
    {
        case 15:
            Re = (Re + 1 > 99) ? 99 : Re + 1;
            return 1;
        case 16:
            Ma = (Ma + 1 > 99) ? 99 : Ma + 1;
            return 1;
        case 17:
            PH = (PH + 1 > 99) ? 99 : PH + 1;
            return 1;
        default: 
        return 0;
    }
}
// A function to check the event 6 and 7 
void set_Def_event_6(int & count_e6, int & record_e6) {
    count_e6 = 0;
    record_e6 = 0;
}
void set_Def_event_7(int & count_e7, int & record_e7) {
    count_e7 = 0;
    record_e7 = 0;
}
void read_Event6 (int & count_e6, int & record_e6 ,int & hp, int maxhp) {
        hp = (hp*5 > maxhp) ? (maxhp) : hp*5;
        set_Def_event_6(count_e6, record_e6);
} 
void read_Event7 (int & count_e7, int & record_e7, int & lev, int inilev) {
        lev = inilev;
        set_Def_event_7 (count_e7, record_e7);
}

//Get iteams in event 19
void get_Event19_items (int matr[][500],int lin, int col,int & RE, int & MA, int & PH){
    int count;
    for (int i = 1; i <= lin ; i ++ ) {
        count = 0;
        for (int j = 1; j <= col; j++) {
            if (count == 3) {
                break;
            }
            else {
                if (get_Items((matr[i][j]-1),RE,MA,PH))
                count ++; // Đếm xem có đủ 3 hay khôngkhông
            }
        }
    }
}
// Function to check whether the knight is a Lancelot or the King Arthur
int check_King_Lance(int HP, int & art, int & lance) {
    if (HP == 999) {
        art = 1;
        return 1;
    }
    if(prime_Number(HP)){
        lance = 1;
        return 1;
    }
    return 0;
}
void check_HP(int & Hp, int maxHp ,int & rescue, int & phoenix, int & count6, int & eve6re, int & count7, int & eve7re) {
  if (Hp > maxHp) {
    Hp = maxHp;
  }
  else if (Hp <= 0) {
    if (phoenix > 0) {
        phoenix --;
        Hp = maxHp;
        if (count6 == 1 or count7 == 1){
            set_Def_event_6(count6,eve6re);
            set_Def_event_7(count7,eve7re);
        }
        else {}
    }
    else rescue = 0;
    }
    else {
    }
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    string line1;
    string map_line2;
    int map[10000]; 
    string map_[10000];
    int countMap = 1; 
    string event13_File; 
    string event13_line2; 
    string event13_str;
    int event13_line1; 
    int event13_array[150]; 
    int event13_array_out[150]; 
    int mtx;
    int mti;
    int maxi;
    int mini;
    int maxi2;
    int mini2;
    int max2_3x;
    int max2_3i;

    string file_asclepius_pack; 
    int r1;
    int c1;
    int event19_array[500][500]; 

    string merlin_pack;
// Open file
    ifstream FileIn(file_input);
    getline (FileIn, line1);
    istringstream in4_hero(line1);
    in4_hero >> HP >>level >> remedy >> maidenkiss >> phoenixdown;
    getline(FileIn,map_line2);
    istringstream iss (map_line2);
    istringstream iss_(map_line2);
    while (iss_ >> map_[countMap]) {
        iss >> map[countMap];
        countMap++;
    }
    getline(FileIn,event13_File,',');
    getline(FileIn,file_asclepius_pack,',');
    getline(FileIn,merlin_pack);
    FileIn.close();
//Open event package
    read_Event13 (event13_array,event13_File,event13_line1);
    read_Event19(event19_array,file_asclepius_pack, c1,r1);
    //Declaration
    float baseDamage[5];
    baseDamage[1] = 1;
    baseDamage[2] = 1.5;
    baseDamage[3] = 4.5;
    baseDamage[4] = 7.5;
    baseDamage[5] = 9.5;       
    
    rescue = -1;
    int arthur = 0;
    int lancelot = 0;
    int art_lan_check;
    int maxHP = HP;
    int inilevel;
    int count_6 = 0;
    int count_7 = 0;
    int count_19 = 0;
    int count_18 = 0;
    int event_record_6 = 0; // dùng cho sự kiện 7.
    int event_record_7 = 0;
    int set; // biến đếm ván thứ mấy
    int n9;
    art_lan_check = check_King_Lance (HP, arthur, lancelot);
    
    for (set = 1; set < countMap; set++) {
        if (rescue == 0 or rescue == 1){
            set--;
            break;
        } 
        int b = set%10;
        int levelO =  set > 6?(b > 5?b : 5) : b;
        switch (map[set])
        {   
            case 0: 
                rescue = 1; 
                break;
            case 1: 
            case 2: 
            case 3: 
            case 4: 
            case 5:
            {      
                float damage = baseDamage[(map[set])]*levelO*10;
                    if (levelO < level or art_lan_check == 1) {
                        level = (level +1 <= 10) ? (level + 1) : 10;
                    }
                    else if (levelO > level){  
                        HP = HP - damage;
                        check_HP(HP, maxHP, rescue, phoenixdown, count_6, event_record_6, count_7, event_record_7);
                    }
                    else {}
                break;   
            } 
            case 6:  
                if (count_6 == 1 or count_7 ==1) {
                    break;
                }
                else {
                    if (levelO < level or art_lan_check == 1) {
                        level = (level +2 <= 10) ? (level + 2) : 10;
                    }
                    else if (levelO > level) {
                        if (remedy <= 0) {
                            count_6 ++;
                            event_record_6 = set + 3;
                            if (HP >=5) {
                                HP = HP/5;
                            }
                            else {
                                HP = 1;
                            }  
                        }  
                        else {
                            remedy--;
                        }
                    }
                    else {}
                }
                break;
            case 7: 
                if (count_6 == 1 or count_7 ==1) {
                    break;
                }
                else {
                    if (levelO < level or art_lan_check == 1) {
                        level = (level +2 <= 10) ? (level + 2) : 10;
                    }
                    else if (levelO > level) {
                        if (maidenkiss <= 0) {
                            count_7 ++;
                            event_record_7 = set + 3;    
                            inilevel = level;
                            level = 1;
                        }
                        else {
                            maidenkiss--;
                        }    
                    }
                    else {}
                }
                break;
            case 11: 
            {
                int n1 = ((level + phoenixdown)%5 + 1)*3;
                HP = (prime_HP(HP+(sum_n1(n1)%100))>maxHP) ? maxHP : prime_HP(HP+(sum_n1(n1)%100));
                break;
            }
            case 12:
            { 
                HP = fibo_HP(HP);
                break;
            }
            case 15:
            case 16:
            case 17:
            {
                get_Items(map[set],remedy,maidenkiss,phoenixdown);
                // nếu biến đếm 6 và 7 bằng 1 và cái tương ứng lớn hơn hoặc bằng 1, thì được dùng
                if (count_6 == 1 and remedy > 0) {
                    read_Event6(count_6,event_record_6,HP,maxHP); 
                    remedy--;}
                if (count_7 == 1 and maidenkiss > 0) {
                    read_Event7(count_7,event_record_7,level,inilevel);
                    maidenkiss--;
                }
                break;
            }
            case 19:
                if (count_19 == 1) break;
                else {
                    get_Event19_items(event19_array,c1,r1,remedy,maidenkiss,phoenixdown);
                    count_19++;
                    // nếu biến đếm 6 và 7 bằng 1 và cái tương ứng lớn hơn hoặc bằng 1, thì được dùng
                    if (count_6 == 1 and remedy > 0) {
                        read_Event6(count_6,event_record_6,HP,maxHP); 
                        remedy--;}
                    if (count_7 == 1 and maidenkiss > 0) {
                        read_Event7(count_7,event_record_7,level,inilevel);
                        maidenkiss--;
                }
                }
                break;
            case 99:
                if (arthur == 1) {
                    level = 10; 
                }
                else if (lancelot == 1 and level >= 8) {
                    level = 10; 
                }
                else if (level == 10) {
                }
                else rescue = 0;
                break;
            case 18:
                if (count_18 == 0) {
                get_Event18(merlin_pack,n9, HP, maxHP);
                count_18 ++;
                }
                else {}
                break;
            default: 
                if (map_[set].substr(0,2) == "13") {
                for (int i = 2; i < map_[set].length(); i ++) {
                    switch (map_[set][i])
                    {
                    case '1':
                        find_Maxmin_index (event13_array, event13_line1, maxi, mini);
                        HP = HP - (maxi + mini);
                        break;
                    case '2':
                        check_Mountain_Up (event13_array, event13_line1, mtx, mti);
                        HP = HP - (mtx + mti);
                        break;
                    case '3':
                        case3_1(event13_array,event13_array_out,event13_line1);
                        find_Maxmin_index_2 (event13_array_out,event13_line1, maxi2, mini2);
                        HP = HP - (maxi2 + mini2);
                        break;
                    case '4':
                        case3_1(event13_array,event13_array_out,event13_line1);
                        check_Case4_2 (event13_array_out,event13_line1,max2_3x,max2_3i);
                        HP = HP - (max2_3x+ max2_3i);
                        break;
                    }
                    check_HP(HP, maxHP, rescue,phoenixdown, count_6, event_record_6, count_7, event_record_7);
                    if (rescue == 0) break;
                }
                }
                else {}
        }
    if (rescue == -1 or rescue == 1) {
        if (event_record_6 == set and count_6 == 1) {
            read_Event6(count_6, event_record_6, HP, maxHP);
        }
        if (event_record_7 == set and count_7 == 1) {
            read_Event7(count_7,event_record_7,level,inilevel);
        }
    } 
    // Check if it end or not
    if (rescue == -1 and set == countMap-1) {
        rescue = 1; }
    else {   
    }
    display(HP,level,remedy, maidenkiss, phoenixdown,rescue);
    }
}
