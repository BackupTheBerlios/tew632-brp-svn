<html>
<head>
<title>TRENDNET | TEW-632BRP | Wizard</title>
<meta http-equiv="Content-Type" content="text/html;">
<link rel="stylesheet" href="style.css" type="text/css">
<script language="JavaScript" src="public_msg.js"></script>
<script language="JavaScript" src="public.js"></script>
<script language="JavaScript">
	function loadSettings(){
	
		set_checked("<% CmoGetCfg("wan_l2tp_dynamic","none"); %>",get_by_name("l2tp_enable"));
		disable_dhcp_static_address(get_by_name("l2tp_enable"), get_by_id("asp_temp_26"), get_by_id("asp_temp_27"), get_by_id("asp_temp_28"));
			
	}

	function send_request(){
		var ip = get_by_id("asp_temp_26").value;	
		var mask = get_by_id("asp_temp_27").value;
		var gateway = get_by_id("asp_temp_28").value;
		
		var ip_addr_msg = replace_msg(all_ip_addr_msg,"IP address");
		var gateway_msg = replace_msg(all_ip_addr_msg,"Gateway address");
		
		var temp_ip_obj = new addr_obj(ip.split("."), ip_addr_msg, false, false);
		var temp_mask_obj = new addr_obj(mask.split("."), subnet_mask_msg, false, false);
		var temp_gateway_obj = new addr_obj(gateway.split("."), gateway_msg, false, false);
		
		if (get_by_name("l2tp_enable")[1].checked){	
			if (!check_lan_setting(temp_ip_obj, temp_mask_obj, temp_gateway_obj)){
				return false;
			}
		}
		
		if (get_by_name("l2tp_enable")[1].checked){
       		get_by_id("asp_temp_23").value = "0";
       		
       	}else{
       		get_by_id("asp_temp_23").value = "1";
       	}

			
		if (!check_pwd("asp_temp_25", "pwd2")){
			return false;
		}
		
		send_submit("form1");
	}
</script>
</head>

<body text="#000000" leftmargin="0" topmargin="0" onLoad="loadSettings();">
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
                <td class="headerbg">Set L2TP Client</td>
              </tr>
            </table>
             <form id="form1" name="form1" method="post" action="apply.cgi">
             	<input type="hidden" id="html_response_page" name="html_response_page" value="wizard6.asp">
	  			<input type="hidden" id="html_response_return_page" name="html_response_return_page" value="<% CmoGetCfg("html_response_return_page","none"); %>">
	  			<input type="hidden" id="reboot_type" name="reboot_type" value="none">
	  			<input type="hidden" id="asp_temp_02" name="asp_temp_02" value="l2tp">
	  			<input type="hidden" id="asp_temp_23" name="asp_temp_23" value="<% CmoGetStatus("asp_temp_23"); %>">
	  			<input type="hidden" id="wan_l2tp_dynamic" name="wan_l2tp_dynamic"  value="<% CmoGetCfg("wan_l2tp_dynamic","none"); %>">
	  			
	  			
                <table width="100%" border="0" cellpadding="3" cellspacing="1" bgcolor="#FFFFFF">
                  <tr class="formarea">
                    <td align=right class="bgblue">&nbsp;</td>
                    <td class="bggrey"><font face="Arial">
                      <input type="radio" name="l2tp_enable" value="1" onClick='disable_dhcp_static_address(get_by_name("l2tp_enable"), get_by_id("asp_temp_26"), get_by_id("asp_temp_27"), get_by_id("asp_temp_28"))'>
                    </font>Dynamic IP&nbsp;<font face="Arial">
                    <input type="radio" name="l2tp_enable" value="0" onClick='disable_dhcp_static_address(get_by_name("l2tp_enable"), get_by_id("asp_temp_26"), get_by_id("asp_temp_27"), get_by_id("asp_temp_28"))'>
                    </font>Static IP</td>
                  </tr>
                  <tr class="formarea">
                    <td align=right class="bgblue"><font face="Arial">My IP</font></td>
                    <td class="bggrey">
                      <input name="asp_temp_26" type=text id="asp_temp_26" value="<% CmoGetCfg("asp_temp_26","none"); %>" size="20" maxlength="15">
                    </td>
                  </tr>
                  <tr class="formarea">
                    <td align=right class="bgblue"> Subnet Mask</td>
                    <td class="bggrey">
                      <input name="asp_temp_27" type=text id="asp_temp_27" value="<% CmoGetCfg("asp_temp_27","none"); %>" size="20" maxlength="15">
                    </td>
                  </tr>
                  <tr class="formarea">
                    <td align=right class="bgblue">Gateway</td>
                    <td class="bggrey" >
                      <input name="asp_temp_28" type=text id="asp_temp_28" value="<% CmoGetCfg("asp_temp_28","none"); %>" size="20" maxlength="15">
                    </td>
                  </tr>
                  <tr>
                    <td align="right" class="bgblue"><font face="Arial">Server IP</font></td>
                    <td bgcolor="#FFFFFF" class="bggrey"><font>
                      <input type="text" id="asp_temp_29" name="asp_temp_29" size=30 maxlength=63 value="<% CmoGetCfg("asp_temp_29","none"); %>">
                    </font></td>
                  </tr>
                  <tr>
                    <td align="right" class="bgblue"><font face="Arial">L2TP Account</font></td>
                    <td bgcolor="#FFFFFF" class="bggrey"><font>
                      <input type="text" id="asp_temp_24" name="asp_temp_24" size=30 maxlength=63 value="<% CmoGetCfg("asp_temp_24","none"); %>">
                    </font></td>
                  </tr>
                  <tr>
                    <td align="right" class="bgblue">L2TP Password</td>
                    <td bgcolor="#FFFFFF" class="bggrey"><input type="password" id="asp_temp_25" name="asp_temp_25" size=30 maxlength=63 value="WDB8WvbXdHtZyM8Ms2RENgHlacJghQyG"></td>
                  </tr>
                  <tr>
                    <td align="right" class="bgblue">Retype Password</td>
                    <td bgcolor="#FFFFFF" class="bggrey"><input type="password" id="pwd2" name="pwd2" size=30 maxlength=63 value="WDB8WvbXdHtZyM8Ms2RENgHlacJghQyG"></td>
                  </tr>
                </table>
                <p>
                  <input type="button" value="&lt; Back" name="back" onClick="window.location='<% CmoGetCfg("html_response_return_page","none"); %>'">
                <input type="button" value="Next &gt;" name="next" onClick="send_request()">
                <input type="button" name="exit" value="Exit" onClick="exit_wizard()">
                </p>
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

</html>
