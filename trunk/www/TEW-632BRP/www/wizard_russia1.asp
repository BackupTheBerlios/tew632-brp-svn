<html>
<head>
<title>TRENDNET | TEW-632BRP | Wizard</title>
<meta http-equiv="Content-Type" content="text/html;">
<link rel="stylesheet" href="style.css" type="text/css">
<script language="JavaScript" src="public_msg.js"></script>
<script language="JavaScript" src="public.js"></script>
<SCRIPT LANGUAGE="JavaScript">
	function loadSettings(){
		get_by_name("country")[0].checked = true;
		get_by_name("ConnType")[0].checked = true;
		
		var connect_type = get_by_id("asp_temp_56").value;
		
			if(connect_type=="wizard_russia2.asp"){
				get_by_name("ConnType")[0].checked = true;
			}else if(connect_type=="wizard_russia4.asp"){
				get_by_name("ConnType")[1].checked = true;
			}else{
				get_by_name("ConnType")[0].checked = true;
			}

		
	}
	
	function send_request(){
		var conn_type = get_checked_value(get_by_name("ConnType"));
		get_by_id("asp_temp_56").value = conn_type;		
		get_by_id("html_response_page").value = conn_type;
		get_by_id("asp_temp_48").value = "0"; //Russia pptp disable
		
	
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
                <td class="headerbg">Set Internet Connection </td>
              </tr>
            </table>
              <form name="form1" id="form1" method="post" action="apply.cgi">
              	<input type="hidden" id="html_response_page" name="html_response_page">
          		<input type="hidden" id="html_response_return_page" name="html_response_return_page" value="wizard_russia1.asp">
          		<input type="hidden" id="reboot_type" name="reboot_type" value="none">
          		<input type="hidden" id="wan_pptp_russia_enable" name="wan_pptp_russia_enable" value="<% CmoGetCfg("wan_pptp_russia_enable","none"); %>">
	  			<input type="hidden" id="asp_temp_22" name="asp_temp_22" value="<% CmoGetCfg("asp_temp_22"); %>">
	  			<input type="hidden" id="asp_temp_56" name="asp_temp_56" value="<% CmoGetCfg("asp_temp_56","none"); %>">
	  			<input type="hidden" id="asp_temp_56" name="asp_temp_48" value="<% CmoGetCfg("asp_temp_48","none"); %>">
				
              <table width="100%" border="0" cellpadding="3" cellspacing="1" bgcolor="#FFFFFF">
                <tr>
                  <td width="144" align="right" bgcolor="#FFFFFF" class="bgblue"><font face="Arial">Country</font></td>
                  <td width="235" bgcolor="#FFFFFF" class="bggrey"><font face="Arial" color="#000000"><font face="Arial" color="#000000">
                    <input type="radio" name="country" value="1">
                  </font>Russia
                  </font></td>
                </tr>
                <tr>
                  <td align="right" bgcolor="#FFFFFF" class="bgblue">City</td>
                  <td bgcolor="#FFFFFF" class="bggrey"><font face="Arial" color="#000000"><font face="Arial" color="#000000">
                    <select id="asp_temp_22" name="asp_temp_22">
                      <option value="vpn.corbina.net">Moscow</option>
                      <option value="vpn.spb.corbina.net">Saint Pertersburg</option>
                      <option value="vpn.klg.corbina.net">Kaluga</option>
                      <option value="vpn.klg.corbina.net">Klin</option>
                      <option value="vpn.tul.corbina.net">Tula</option>
                      <option value="vpn.yar.corbina.net">Yaroslavl</option>
                    </select>
                  </font>
                  </font></td>
                </tr>
                <tr>
                  <td align="right" bgcolor="#FFFFFF" class="bgblue"><font face="Arial">Provider</font></td>
                  <td bgcolor="#FFFFFF" class="bggrey"><font face="Arial" color="#000000"><font face="Arial" color="#000000"><font face="Arial" color="#000000">
                  <font face="Arial" color="#000000"><font face="Arial" color="#000000"><font face="Arial" color="#000000">
                  <select id="select" name="select">
                    <option value="sm-server">Corbina telecom</option>
                  </select>
                  </font></font></font> </font></font>
</font></td>
                </tr>
                <tr>
                  <td align="right" bgcolor="#FFFFFF" class="bgblue"><font face="Arial">Service</font></td>
                  <td bgcolor="#FFFFFF" class="bggrey"><font face="Arial" color="#000000">
                  <font face="Arial" color="#000000"><font face="Arial" color="#000000">
                  <select id="asp_temp_57" name="asp_temp_57">
                    <option value="PPTP">PPTP</option>
                  </select>
                  </font></font></font></td>
                </tr>
                <tr>
                  <td align="right" bgcolor="#FFFFFF" class="bgblue">&nbsp;</td>
                  <td bgcolor="#FFFFFF" class="bggrey">
				  		<font face="Arial" color="#000000"><font face="Arial" color="#000000"><font face="Arial" color="#000000">
                      	<input type="radio" name="ConnType"  value="wizard_russia2.asp">
						</font></font>Select from the list (advised)</font><br>
						<font face="Arial" color="#000000"><font face="Arial" color="#000000"><font face="Arial" color="#000000">
						<input type="radio" name="ConnType" value="wizard_russia4.asp">
                  		</font></font></font>Manual setup
					</td>
                </tr>
              </table>
               <br>
               <input type="button" value="&lt; Back" id="back" name="back" onClick="window.location='wizard3.asp'">
               <input type="button" value="Next &gt;" id="next" name="next" onClick="send_request()">
               <input type="button" id="exit" name="exit" value="Exit" onClick="exit_wizard()">
              
              </form>
            </td>
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
