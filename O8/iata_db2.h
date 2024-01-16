#define IATA_F "iata_data.csv"  /* 空港データのファイル */
#define MAX_RECORDS 2700  /* レコード数の上限 */

#define KEY_LEN 3  /* 空港コード (キー) の文字数 */
#define KEY_FMT "%3s"  /* 空港コード (キー) の入力用フォーマット */
#define DATA_LEN 127  /* 空港データの最大文字数 */
#define LINE_LEN (KEY_LEN + 1 + DATA_LEN + 1)  /* 1行の最大文字数 */

/* 1 レコードのデータ */
typedef struct record_s{
  char key[KEY_LEN+1];  /* 空港コード (キー) */
  char* data;  /* 空港データの */
  struct record_s *next;  /* 次の節点 */
} record_t;


/* データベース (全データ) */
typedef struct {
  int n;  /* データ (レコード) 数 */
  record_t record[MAX_RECORDS];  /* データ (レコード) の配列 */
} db_t;


int db_hash_f(char key[]); /* ハッシュ関数 */

void db_init(db_t *db); /* データベースの初期化 */
void db_delete(db_t *db); /* データの破棄 */
void db_hash_load(db_t *db); /* データベースにファイルからデータを読み込む (ハッシュ用) */
char *db_hash_search(db_t *db, char key[]); /* ハッシュによる探索 */