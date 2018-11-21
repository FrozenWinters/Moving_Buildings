#include <iostream>

using namespace std;

int M[26];
int F[26];
int H[26];
bool invert;
bool undo;

void action(bool white, int src, int dest){
  if(undo){
    swap(src, dest);
  }

  if(invert){
    white = !white;
    src = (src + 1) % 4 + 1;
    dest = (dest + 1) % 4 + 1;
  }

  if(white){
    cout << "MOVE white FLOOR FROM LOT " << src << " to LOT " << dest << endl;
  } else{
    cout << "MOVE black FLOOR FROM LOT " << src << " to LOT " << dest << endl;
  }
}

void Hanoi(int h, int ind, int start, int end, int middle, bool white){
  if(ind < H[h - 1]){
    Hanoi(h - 1, ind, start, middle, end, white);
  } else if(ind -= H[h - 1], ind == 0){
    action(white, start, end);
  } else{
    ind -= 1;
    Hanoi(h - 1, ind, middle, end, start, white);
  }
}

/* Mnemonic: white? at free A to partisan B
 * !white? at free C to free A */
void Fumble(int h, int ind, int A, int B, int C, int D, bool white){
  if(ind < F[h - 1]){
    Fumble(h - 1, ind, C, D, A, B, !white);
  } else if(ind -= F[h - 1], ind == 0){
    action(white, A, B);
  } else if(ind -= 1, ind < H[h - 1]){
    Hanoi(h - 1, ind, C, B, A, white);
  } else if(ind -= H[h - 1], ind == 0){
    action(!white, C, A);
  } else{
    ind -= 1;
    Hanoi(h - 1, ind, D, A, C, !white);
  }
}

void Move(int h, int ind){
  invert = (h % 2);
  undo = false;
  if(ind < F[h - 1]){
    Fumble(h - 1, ind, 1, 2, 3, 4, true);
  } else if(ind -= F[h - 1], ind == 0){
    action(false, 3, 4);
  } else if(ind -= 1, ind < H[h - 1]){
    Hanoi(h - 1, ind, 1, 4, 3, false);
  } else if(ind -= H[h - 1], ind == 0){
    action(true, 1, 3);
  } else if(ind -= 1, ind < H[h - 1]){
    Hanoi(h - 1, ind, 4, 3, 1, false);
  } else if(ind -= H[h - 1], ind == 0){
    action(false, 4, 1);
  } else{
    //Do it backwards
    ind = F[h - 1] - ind;
    undo = true;
    Fumble(h - 1, ind, 3, 2, 1, 4, true);
  }
}

int main(){
  M[0] = F[0] = H[0] = 0;
  for(int i = 1; i < 26; i++){
    H[i] = 2 * H[i - 1] + 1;
    F[i] = 2 * H[i];
    M[i] = 3 * H[i];
  }

  int P;
  cin >> P;
  for(int i = 0; i < P; i++){
    int K, N, S;
    cin >> K >> N >> S;
    cout << K << " " << M[N] << " ";
    Move(N, S - 1);
  }
}
