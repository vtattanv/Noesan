#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REP 500
#define N 500

void repage(void)
{
  int i = 0;
  while (i != 1) {
    printf ("[進む:1] ");
    scanf ("%d", &i);
  }
  for (i = 0; i < REP; i++) printf ("\n");
}

void rep_only(void)
{
  int i;
  for (i = 0; i < REP; i++) printf ("\n");
}

void rand_sort(int num, int name_num[num])
{
  srand((unsigned)time(NULL));
  int i, s, a[num], b[num];

  for (i = 0; i < num; i++) {
    a[i] = 0;
    b[i] = 0;
  }

  i = 0;
  while (i < num) {
    s = rand() % num;
    if (b[s] == 0) {
      a[i] = s;
      b[s] = 1;
      i++;
    }
  }
  for (i = 0; i < num; i++) {
    if (i == num - 1) name_num[a[i]] = a[0];
    else name_num[a[i]] = a[i+1];
  }
}

int main(void)
{
  int i, j, s, t, num;
  
  //人数・名前の入力
  printf ("人数を入力してください　...");
  scanf ("%d", &num);

  int name_num[num];
  char player[num][N];

  for (i = 0; i < num; i++) {
    printf ("%d人目の名前を入力してください　...", i+1);
    scanf ("%s", player[i]);
  }

  rand_sort(num, name_num);

  //相手の確認
  rep_only();
  for (i = 0; i < num; i++) {
    printf (" %s さんがこの画面を見てください。\n", player[i]);
    printf ("相手の名前を表示します。他の人に見られないように表示してください。\n");
    s = 0;
    repage();
    printf (" %s さんの相手の名前は %s さんです。\n", player[i], player[name_num[i]]);
    repage();
  }

  printf ("終了\n\n");
  return 0;
}
