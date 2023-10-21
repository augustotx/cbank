void encrypt(char *, const char *);
void decrypt(char *, const char *);
int init();
void clienterror();
int input(char *, char *, int);
int intinput(char *);
int strcompare(char *,char *);
int newclient(char *, struct client *,int);
int listclients(int,struct client *);
int validateclient(char *, int, struct client *);
int makeextr(struct client *, int, double, double, int);
int deleteclient(char *,int ,struct client *);
int deposito(char *,struct client *,int);
int debito(char *,struct client *,int);
int showextr(char *,struct client *,int);
int savedata(struct clients *, int);
int loaddata(struct clients *, int);
int transfer(char *, struct client *, int );