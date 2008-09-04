<html>
<head>
<title>TRENDNET | TEW-632BRP | Wizard</title>
<meta http-equiv="Content-Type" content="text/html;">
<link rel="stylesheet" href="style.css" type="text/css">
<script language="JavaScript" src="public.js"></script>
</head>
<script language="JavaScript">
var submit_button_flag = 0;
	function set_time_zone(){
		set_selectIndex(get_by_id("asp_temp_01").value, get_by_id("time_zone_wizard"));
	}
	
	function send_request(){
		get_by_id("asp_temp_01").value = get_select_value(get_by_id("time_zone_wizard"));
		
		if(submit_button_flag == 0){
			submit_button_flag = 1;
			return true;
		}else{
			return false;
		}
	}
	
</script>
<body text="#000000" leftmargin="0" topmargin="0">
<table width="459" height="324" border="0" cellpadding="0" cellspacing="0" bgcolor="334255">
    <tr>
      <td height="49"><img src="bg_wizard_2.gif" width="459" height="49"></td>
    </tr>
    <tr>
      <td valign="top" background="bg_wizard_3.gif"><table width="459" border="0" cellpadding="0" cellspacing="0">
          <tr>
            <td colspan="3"><img src="spacer.gif" width="30" height="10"></td>
          </tr>
          <tr>
            <td width="7%"><img src="spacer.gif" width="30" height="60"></td>
            <td width="86%" align="center"><table width="100%" border="0" cellpadding="0" cellspacing="0">
              <tr>
                <td class="headerbg">Choose Time Zone </td>
              </tr>
            </table>
              <form id="form1" name="form1" method="post" action="apply.cgi">
              	<input type="hidden" id="html_response_page" name="html_response_page" value="wizard3.asp">
          		<input type="hidden" id="html_response_return_page" name="html_response_return_page" value="wizard2.asp">
          		<input type="hidden" id="reboot_type" name="reboot_type" value="none">
          		
              	<input type="hidden" id="asp_temp_01" name="asp_temp_01" value="<% CmoGetCfg("asp_temp_01","none"); %>">			
              
              <table width="100%" border="0" cellpadding="3" cellspacing="1" bgcolor="#FFFFFF">
                <tr>
                  <td class="bggrey"><font>
                    <select id="time_zone_wizard" name="time_zone_wizard" size="1">
                      <option value="-192">(GMT-12:00) Eniwetok, Kwajalein</option>
                      <option value="-176">(GMT-11:00) Midway Island, Samoa</option>
                      <option value="-160">(GMT-10:00) Hawaii</option>
                      <option value="-144">(GMT-09:00) Alaska</option>
                      <option value="-128">(GMT-08:00) Pacific Time (US &amp; Canada)</option>
                      <option value="-112">(GMT-07:00) Arizona</option>
                      <option value="-113">(GMT-07:00) Mountain Time (US &amp; Canada)</option>
                      <option value="-96">(GMT-06:00) Central Time (US &amp; Canada)</option>
                      <option value="-97">(GMT-06:00) Mexico City, Tegucigalpa</option>
                      <option value="-80">(GMT-05:00) Bogota, Lima, Quito</option>
                      <option value="-81">(GMT-05:00) Eastern Time (US &amp; Canada)</option>
                      <option value="-82">(GMT-05:00) Indiana (East)</option>
                      <option value="-64">(GMT-04:00) Atlantic Time (US &amp; Canada)</option>
                      <option value="-65">(GMT-04:00) Caracas, La Paz</option>
                      <option value="-56">(GMT-03:30) Newfoundland</option>
                      <option value="-48">(GMT-03:00) Brasilia</option>
                      <option value="-49">(GMT-03:00) Buenos Aires, Georgetown</option>
                      <option value="-32">(GMT-02:00) Mid-Atlantic</option>
                      <option value="-16">(GMT-01:00) Azores, Cape Verde Is.</option>
                      <option value="0">(GMT) Casablanca, Monrovia</option>
                      <option value="1">(GMT) Dublin, Edinburgh, Lisbon, London</option>
                      <option value="16">(GMT+01:00) Amsterdam, Berlin, Bern, Rome,
                        Stockholm, Vienna</option>
                      <option value="17">(GMT+01:00) Belgrade, Bratislave, Budapest,
                        Ljubljana, Prague</option>
                      <option value="18">(GMT+01:00) Brussels, Copenhagen, Madrid, Paris,
                        Vilnius</option>
                      <option value="19">(GMT+01:00) Sarajevo, Skopje, Sofija, Warsaw,
                        Zagreb</option>
                      <option value="32">(GMT+02:00) Athens, Bucharest, Cairo, Istanbul,
                        Minsk</option>
                      <option value="33">(GMT+02:00) Harare, Helsinki, Jerusalem, Pretoria,
                        Riga, Tallinn</option>
                      <option value="48">(GMT+03:00) Baghdad, Kuwait, Riyadh</option>
                      <option value="49">(GMT+03:00) Moscow, St.Petersburg, Volgograd</option>
                      <option value="56">(GMT+03:30) Tehran</option>
                      <option value="64">(GMT+04:00) Abu Dhabi, Baku, Muscat, Tbilist</option>
                      <option value="72">(GMT+04:30) Kabul</option>
                      <option value="90">(GMT+05:00) EKaterinburg, Islamabad, Karachi,
                        Tashikent</option>
                      <option value="88">(GMT+05:30) New Delhi</option>
                      <option value="96">(GMT+06:00) Astana, Almaty, Colombo, Dhaka</option>
                      <option value="112">(GMT+07:00) Bangkok, Hanoi, Jakarta</option>
                      <option value="128">(GMT+08:00) Beijing, Hong Kong, Singapore,
                        Taipei</option>
                      <option value="144">(GMT+09:00) Seoul, Tokyo, Yakutsk</option>
                      <option value="152">(GMT+09:30) Adelaide, Darwin</option>
                      <option value="160">(GMT+10:00) Canberra, Guam, Port Moresby,
                        Vladivostok</option>
                      <option value="176">(GMT+11:00) Magadan, Solomon Islands</option>
                      <option value="192">(GMT+12:00) Fiji, Kamchatka, Marshall Islands,
                        Wellington, Auckland</option>
                    </select>
                  </font></td>
                </tr>
              </table>
              <br>
              <input type="button" value="&lt; Back" name="back" onClick="window.location='<% CmoGetCfg("html_response_return_page","none"); %>'">
              <input type="submit" value="Next &gt;" name="next" onClick="send_request()">
              <input type="button" name="exit" value="Exit" onClick="exit_wizard()">
              
              </form></td>
            <td width="7%"><img src="spacer.gif" width="30" height="60"></td>
          </tr>
      </table></td>
    </tr>
    <tr>
      <td height="14"><img src="bg_wizard_4.gif" width="459"></td>
    </tr>
  </table>
</body>
<script>set_time_zone();</script>
</html>
