<html>
<head>
<meta http-equiv="Content-Type" content="text/html;">
<title>TRENDNET | TEW-632BRP | Main | LAN &amp; DHCP Server</title>
<link rel="stylesheet" href="style.css" type="text/css">
<script language="JavaScript" src="public_msg.js"></script>
<script language="JavaScript" src="public.js"></script>
<script language="JavaScript">
	var DataArray = new Array();

	function display_wizard(display){
		if (!display){
			show_wizard('wizard.asp');
		}
	}

	function disable_dhcp_server(){
		var dhcp = get_by_name("dhcp");
		
		disable_dhcp(dhcp[1].checked, get_by_id("dhcpd_start"), get_by_id("dhcpd_end"));
		get_by_id("dhcpd_domain_name").disabled = dhcp[1].checked;
		get_by_id("lease_time").disabled = dhcp[1].checked;
	}

    function send_request(){    	
		var ip = get_by_id("lan_ipaddr").value;
		var mask = get_by_id("lan_netmask").value;
		var dhcp = get_by_name("dhcp");
		var start_ip = get_by_id("dhcpd_start").value;
		var end_ip = get_by_id("dhcpd_end").value;
		
		var ip_addr_msg = replace_msg(all_ip_addr_msg,"IP address");
		var start_ip_addr_msg = replace_msg(all_ip_addr_msg,"Start IP address");
		var end_ip_addr_msg = replace_msg(all_ip_addr_msg,"End IP address");
		
		var temp_ip_obj = new addr_obj(ip.split("."), ip_addr_msg, false, false);
		var temp_mask_obj = new addr_obj(mask.split("."), subnet_mask_msg, false, false);
		var temp_start_ip_obj = new addr_obj(start_ip.split("."), start_ip_addr_msg, false, false);
		var temp_end_ip_obj = new addr_obj(end_ip.split("."), end_ip_addr_msg, false, false);
				
		if (!check_address(temp_ip_obj, temp_mask_obj) || !check_mask(temp_mask_obj)){		
			return false;
		}		
			
		if (dhcp[0].checked){
			if (!check_address(temp_start_ip_obj, temp_mask_obj) || !check_address(temp_end_ip_obj, temp_mask_obj)){
				return false;
			}
				
			if (!check_domain(temp_ip_obj, temp_mask_obj, temp_start_ip_obj)){
				alert(addstr(msg[MSG2],"Start IP address"));
				return false;
			}
				
			if (!check_domain(temp_ip_obj, temp_mask_obj, temp_end_ip_obj)){
				alert(addstr(msg[MSG2],"End IP address"));
				return false;
			}
				
			if (!check_ip_order(temp_start_ip_obj, temp_end_ip_obj)){
				alert(msg[MSG4]);
				return false;
			}
		get_by_id("dhcpd_enable").value = 1;
		}
		else if(dhcp[1].checked)
			get_by_id("dhcpd_enable").value = 0;

		get_by_id("dhcpd_lease_time").value = get_by_id("lease_time").value;
		if ((ip_num(temp_ip_obj.addr) >= ip_num(temp_start_ip_obj.addr)) && (ip_num(temp_ip_obj.addr) <= ip_num(temp_end_ip_obj.addr)))
		{
			alert("LAN IP is conflicted with LAN IP range, please enter again.");
			return false;
		}
		send_submit("form1");
	}
	
	function loadSettings(){
		set_checked(get_by_id("dhcpd_enable").value,get_by_name("dhcp"))
		set_selectIndex(get_by_id("dhcpd_lease_time").value, get_by_id("lease_time"));
	}
	
	function Data(name, interfx, ip, mac, onList) 
	{
		this.Name = name;
		this.Interface = interfx;
		this.IP = ip ;
		this.MAC = mac ;
		this.OnList = onList ;
	}
	
	function set_dhcplist(){
		var myData = get_by_id("dhcp_list").value.split(",");
		var index=1;
		for (var i=0 ; i<myData.length;i++){
			var temp_data = myData[i].split("/");
			if(temp_data.length > 1){
				DataArray[DataArray.length++] = new Data(temp_data[1],"LAN", temp_data[0], temp_data[2],index);
				index++;
			}
		}
	}
</script>
</head>

<body onLoad="MM_preloadImages('but_wizard_1.gif','but_status_1.gif','but_tools_1.gif','but_main_1.gif','but_wireless_1.gif','but_routing_1.gif','but_access_1.gif','but_management_1.gif','but_help1_1.gif');">
<table width="750" border="0" cellpadding="0" cellspacing="0">
  <tr>
    <td width="21"><img src="c1_tl.gif" width="21" height="21"></td>
    <td width="708" background="bg1_t.gif"><img src="top_1.gif" width="390" height="21"></td>
    <td width="21"><img src="c1_tr.gif" width="21" height="21"></td>
  </tr>
  <tr>
    <td valign="top" background="bg1_l.gif"><img src="top_2.gif" width="21" height="69"></td>
    <td background="bg.gif"><table width="100%" border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td width="13%"><img src="logo.gif" width="270" height="69"></td>
        <td width="87%" align="right"><img src="description.gif"></td>
      </tr>
    </table>
      <table width="100%" border="0" cellpadding="0" cellspacing="0">
        <tr>
          <td width="20%" valign="top"><table width="56%" border="0" cellpadding="0" cellspacing="0">
            <tr>
              <td><a href="lan.asp"><img src="but_main_1.gif" name="Image2" width="144" height="28" border="0" id="Image2" onMouseOver="MM_swapImage('Image2','','but_main_1.gif',1)" onMouseOut="MM_swapImgRestore()"></a></td>
            </tr>
            <tr>
              <td><table width="100%" border="0" cellpadding="2" class="submenubg">
                <tr>
                  <td width="13%" align="right"><font color="#FFFFFF">&bull;</font></td>
                  <td width="87%"><a href="lan.asp" class="submenus"><b><u>LAN &amp; DHCP Server </u></b></a></td>
                </tr>
                <tr>
                  <td align="right"><font color="#FFFFFF">&bull;</font></td>
                  <td><a href="wan.asp" class="submenus"><b>WAN</b></a></td>
                </tr>
                <tr>
                  <td align="right"><font color="#FFFFFF">&bull;</font></td>
                  <td><a href="password.asp" class="submenus"><b>Password</b></a></td>
                </tr>
                <tr>
                  <td align="right"><font color="#FFFFFF">&bull;</font></td>
                  <td><a href="time.asp" class="submenus"><b>Time</b></a></td>
                </tr>
                <tr>
                  <td align="right"><font color="#FFFFFF">&bull;</font></td>
                  <td><a href="ddns.asp" class="submenus"><b>Dynamic DNS </b></a></td>
                </tr>
              </table></td>
            </tr>
            <tr>
              <td><img src="spacer.gif" width="8" height="8"></td>
            </tr>
            <tr>
              <td><a href="wireless_basic.asp"><img src="but_wireless_0.gif" name="Image3" width="144" height="28" border="0" id="Image3" onMouseOver="MM_swapImage('Image3','','but_wireless_1.gif',1)" onMouseOut="MM_swapImgRestore()"></a><a href="w_basic.asp"></a></td>
            </tr>
            <tr>
              <td><img src="spacer.gif" width="8" height="8"></td>
            </tr>
            <tr>
              <td><a href="status.asp"><img src="but_status_0.gif" name="Image1" width="144" height="28" border="0" id="Image1" onMouseOver="MM_swapImage('Image1','','but_status_1.gif',1)" onMouseOut="MM_swapImgRestore()"></a></td>
            </tr>
            <tr>
              <td><img src="spacer.gif" width="8" height="8"></td>
            </tr>
            <tr>
              <td><a href="static_routing.asp"><img src="but_routing_0.gif" name="Image4" width="144" height="28" border="0" id="Image4" onMouseOver="MM_swapImage('Image4','','but_routing_1.gif',1)" onMouseOut="MM_swapImgRestore()"></a></td>
            </tr>
            <tr>
              <td><img src="spacer.gif" width="8" height="8"></td>
            </tr>
            <tr>
              <td><a href="filters.asp"><img src="but_access_0.gif" name="Image5" width="144" height="28" border="0" id="Image5" onMouseOver="MM_swapImage('Image5','','but_access_1.gif',1)" onMouseOut="MM_swapImgRestore()"></a></td>
            </tr>
            <tr>
              <td><img src="spacer.gif" width="8" height="8"></td>
            </tr>
            <tr>
              <td><a href="remote_management.asp"><img src="but_management_0.gif" width="144" height="28" border="0" id="Image6" onMouseOver="MM_swapImage('Image6','','but_management_1.gif',1)" onMouseOut="MM_swapImgRestore()"></a></td>
            </tr>
            <tr>
              <td><img src="spacer.gif" width="8" height="8"></td>
            </tr>
            <tr>
              <td><a href="restart.asp"><img src="but_tools_0.gif" width="144" height="28" border="0" id="Image7" onMouseOver="MM_swapImage('Image7','','but_tools_1.gif',1)" onMouseOut="MM_swapImgRestore()"></a></td>
            </tr>
            <tr>
              <td><img src="spacer.gif" width="8" height="8"></td>
            </tr>
            <tr>
              <td><a href="#" onClick="show_wizard('wizard.asp')"><img src="but_wizard_0.gif" name="Image71" width="144" height="28" border="0" id="Image71" onMouseOver="MM_swapImage('Image71','','but_wizard_1.gif',1)" onMouseOut="MM_swapImgRestore()"></a></td>
            </tr>
            <tr>
              <td><img src="spacer.gif" width="15" height="15"></td>
            </tr>
          </table></td>
          <td width="2%"><img src="spacer.gif" width="15" height="15"></td>
          <td width="78%" valign="top"><table width="100%" border="0" cellpadding="0" cellspacing="0">
            <tr>
              <td width="10"><img src="c2_tl.gif" width="10" height="10"></td>
              <td width="531" background="bg2_t.gif"><img src="spacer.gif" width="10" height="10"></td>
              <td width="10"><img src="c2_tr.gif" width="10" height="10"></td>
            </tr>
            <tr>
              <td background="bg2_l.gif"><img src="spacer.gif" width="10" height="10"></td>
              <td height="400" valign="top" background="bg3.gif">
                  <table width="100%" border="0" cellpadding="3" cellspacing="0">
                    <tr>
                      <td width="85%" class="headerbg">LAN &amp; DHCP Server</td>
                      <td width="15%" class="headerbg"><a href="help_main.asp#lanski_dhcp_server" target="_blank"><img src="but_help1_0.gif" width="69" height="28" border="0" id="Image8" onMouseOver="MM_swapImage('Image8','','but_help1_1.gif',1)" onMouseOut="MM_swapImgRestore()"></a></td>
                    </tr>
                  </table>
				  <form id="form1" name="form1" method="post" action="apply.cgi">
				  <input type="hidden" name="html_response_page" value="back.asp">
				  <input type="hidden" name="html_response_message" value="The setting is saved.">
				  <input type="hidden" name="html_response_return_page" value="lan.asp">
				  <input type="hidden" id="dhcpd_lease_time" name="dhcpd_lease_time" value="<% CmoGetCfg("dhcpd_lease_time","none"); %>">
				  <input type="hidden" id="dhcp_list" name="dhcp_list" value="<% CmoGetList("dhcpd_leased_table"); %>">
				  <input type="hidden" id="reboot_type" name="reboot_type" value="lan">
                  <table width="100%" border="0" cellpadding="5" cellspacing="1" bgcolor="#FFFFFF">
                    <tr>
                      <td align="right" class="bgblue">Host Name </td>
                      <td width="404" bgcolor="#FFFFFF" class="bggrey">
                      <input type="text" id="hostname" name="hostname" size="20" maxlength="19" value="<% CmoGetCfg("hostname","none"); %>">
                     </td>
                    </tr>
                    <tr>
                      <td align="right" class="bgblue">IP Address </td>
                      <td width="404" bgcolor="#FFFFFF" class="bggrey"> 
                       <input name="lan_ipaddr" type="text" id="lan_ipaddr" size="16" maxlength="15" value="<% CmoGetCfg("lan_ipaddr","none"); %>">
                     </td>
                    </tr>
                    <tr>
                      <td align="right" class="bgblue">Subnet Mask </td>
                      <td width="404" bgcolor="#FFFFFF" class="bggrey">
                        <input name="lan_netmask" type="text" id="lan_netmask" size="16" maxlength="15" value="<% CmoGetCfg("lan_netmask","none"); %>">
                     </td>
                    </tr>
                    <tr>
                      <td align="right" class="bgblue">DHCP Server </td>
                      <td width="404" bgcolor="#FFFFFF" class="bggrey">
                        <input type="hidden" id="dhcpd_enable" name="dhcpd_enable" value="<% CmoGetCfg("dhcpd_enable","none"); %>">
                        <input type="radio" name="dhcp" value="1" onClick="disable_dhcp_server()">
                        Enabled
                        <input type="radio" name="dhcp" value="0" onClick="disable_dhcp_server()">
                        Disabled</td>
                    </tr>
                    <tr>
                      <td align="right" class="bgblue">Start IP </td>
                      <td width="404" bgcolor="#FFFFFF" class="bggrey">
                       
                       <input type="text" id="dhcpd_start" name="dhcpd_start" size="16" maxlength="15" value="<% CmoGetCfg("dhcpd_start","none"); %>">
                     </td>
                    </tr>
                    <tr>
                      <td align="right" class="bgblue">End IP </td>
                      <td width="404" bgcolor="#FFFFFF" class="bggrey">
                       <input type="text" id="dhcpd_end" name="dhcpd_end" size="16" maxlength="15" value="<% CmoGetCfg("dhcpd_end","none"); %>">
                     </td>
                    </tr>
                    <tr>
                      <td align="right" class="bgblue">Domain Name </td>
                      <td width="404" bgcolor="#FFFFFF" class="bggrey">
                      <input name="dhcpd_domain_name" type="text" id="dhcpd_domain_name" size="40" maxlength="31" value="<% CmoGetCfg("dhcpd_domain_name","none"); %>">
                    </tr>
                    <tr>
                      <td align="right" class="bgblue">Lease
                        Time </td>
                      <td width="404" bgcolor="#FFFFFF" class="bggrey"><font color="#FFFFFF"  face=Arial size=2>
                        <select id="lease_time" name="lease_time" size=1>
                          <option value="60">1 Hour</option>
                          <option value="120">2 Hours</option>
                          <option value="180">3 Hours</option>
                          <option value="1440">1 Day</option>
                          <option value="2880">2 Days</option>
                          <option value="4320">3 Days</option>
                          <option value="10080">1 Week</option>
                        </select>
                      </font> </td>
                    </tr>
                    <tr>
                      <td class="bgblue">&nbsp;</td>
                      <td bgcolor="#FFFFFF" class="bggrey2">
                      	<input type="button" id="cancel" name="cancel" value="Cancel" onClick="window.location='lan.asp'">
						<input type="button" id="apply" name="apply" value="Apply" onClick="send_request()">
                      </td>
                    </tr>
                  </table>
                  <p>&nbsp;</p>
                </form>                
                <table width="100%" border="0" cellpadding="5" cellspacing="1" bgcolor="#FFFFFF">
                  <tr>
                    <td align="center" bgcolor="#C5CEDA"><b>Host Name</b></td>
                    <td align="center" bgcolor="#C5CEDA"><b>IP Address</b></td>
                    <td align="center" bgcolor="#C5CEDA"><b>MAC Address</b></td>
                  </tr>
                  <script>
	                set_dhcplist();
					for(i=0;i<DataArray.length;i++){
						document.write("<tr bgcolor=\"#F0F0F0\" align=\"center\">"+
							  
							  "<td>"+ DataArray[i].IP +"</td>"+
							  "<td>"+ DataArray[i].Name +"</td>"+
							  "<td>"+ DataArray[i].MAC.toUpperCase() +"</td>"+
							  "</tr>");
					}
                  </script>
                </table>                
                <p>&nbsp;</p></td>
              <td background="bg2_r.gif"><img src="spacer.gif" width="10" height="10"></td>
            </tr>
            <tr>
              <td><img src="c2_bl.gif" width="10" height="10"></td>
              <td background="bg2_b.gif"><img src="spacer.gif" width="10" height="10"></td>
              <td><img src="c2_br.gif" width="10" height="10"></td>
            </tr>
          </table></td>
        </tr>
      </table>      
      <br>
      <br></td>
    <td background="bg1_r.gif">&nbsp;</td>
  </tr>
  <tr>
    <td><img src="c1_bl.gif" width="21" height="20"></td>
    <td align="right" background="bg1_b.gif"><img src="copyright.gif" width="264" height="20"></td>
    <td><img src="c1_br.gif" width="21" height="20"></td>
  </tr>
</table>
<script>
    display_wizard(<% CmoGetCfg("blank_status","none"); %>);	
    loadSettings();
	disable_dhcp_server();
</script>
</body>
</html>
