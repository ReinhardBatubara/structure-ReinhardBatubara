// 12S22001 - Winfrey Nainggolan
// 12S22011 - Reinhard Batubara

#include <stdio.h>
#include <string.h>


typedef struct {
    char word[100];
    char meaning[100];
} kamus_t ;

enum perintah {
    register1,// 0
    find, // 1
    finish // 2
};
int main(int _argc, char **_argv) {
// deklarasi variabel
    kamus_t data[5];
    char input[100];
    enum perintah daftar_perintah;
    int sum_data = 0;
    int found = 1;


    // loop utama program
    while (found == 1) {

        scanf("%s", &input);
        input[strcspn(input, "\n")] = 0; // menghilangkan karakter newline dari input

        // memeriksa tipe perintah
        if (strcmp(input, "register") == 0) {
            daftar_perintah = register1;
        } else if (strcmp(input, "find") == 0) {
            daftar_perintah = find;
        } else if (strcmp(input, "---") == 0) {
              daftar_perintah = finish;
        }

        // menjalankan perintah sesuai tipe
        if (daftar_perintah == register1) {
            if (sum_data >= 5) {
                continue;
            }

            char word[100], meaning[100];
            scanf("%s",&word);
            word[strcspn(word, "\n")] = 0;

            scanf("%s",&meaning);
            meaning[strcspn(meaning, "\n")] = 0;

            strcpy(data[sum_data].word, word);
            strcpy(data[sum_data].meaning, meaning);
            sum_data++;

        } else if (daftar_perintah == find) {
            char word[100];
            scanf("%s", &word);
            word[strcspn(word, "\n")] = 0;

            for (int i = 0; i < sum_data; i++) {
                if (strcmp(data[i].word, word) == 0) {
                    printf("%s#%s\n", data[i].word, data[i].meaning);
                    found = 1;
                    break;
                }
            }

        
        } else if (daftar_perintah == finish) {
            break;
        }
    }

    return 0;
}
