int time()
{
   time_t now=time(0);
   tm *ltm=localtime(&now);   
   printf("%02d.%02d.%02d %02d:%02d:%02d\n",1900+ltm->tm_year,1+ltm->tm_mon,ltm->tm_mday,ltm->tm_hour,ltm->tm_min,ltm->tm_sec);
   return 0;
}