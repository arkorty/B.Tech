{ 
  int a[3], t1, t2;
  t1 = 2;
  a[0] = 1;
  a[1] = 2;
  a[t1] = 3;

  t2 = -(a[2] + t1 * 6) / (a[2] - t1);

  if t2 > 5 then
      print(t2);
  else {
      int t3;
      t3 = 99;
      t2 = -25;
      print(-t1 + t2 * t3);  /* comment */
  } endif
}
