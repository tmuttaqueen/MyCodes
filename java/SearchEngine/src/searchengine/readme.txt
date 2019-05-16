
<!DOCTYPE HTML><html class="js" lang="en" xmlns="http://www.w3.org/1999/xhtml">
    <head profile="http://gmpg.org/xfn/11">
<script src="/forums/static/111213/js/perf/stub.js" type="text/javascript"></script><script src="/forums/jslibrary/1479750578000/sfdc/main.js" type="text/javascript"></script><script src="/forums/jslibrary/jslabels/1479844900000/en_US.js" type="text/javascript"></script><script src="/forums/EXT/ext-3.0.0/ext-core.js" type="text/javascript"></script><script src="/forums/jslibrary/1479750578000/sfdc/ChatterAnswers.js" type="text/javascript"></script><script src="/ckeditor/ckeditor-4.x/rel/ckeditor.js?t=4.5.7" type="text/javascript"></script><script src="/forums/jslibrary/1479750578000/sfdc/ChatterAnswersJSAPI-1.0.js" type="text/javascript"></script><script src="/forums/jslibrary/1479750578000/sfdc/Zen.js" type="text/javascript"></script><link class="user" href="https://res.cloudinary.com/hy4kyit2a/raw/upload/qTip2.css" rel="stylesheet" type="text/css" /><link class="user" href="/forums/sCSS/38.0/sprites/1477585684000/Theme3/default/gc/common.css" rel="stylesheet" type="text/css" /><link class="user" href="/forums/sCSS/38.0/sprites/1477585684000/Theme3/default/gc/ChatterAnswers.css" rel="stylesheet" type="text/css" /><link class="user" href="/forums/sCSS/38.0/sprites/1477585684000/Theme3/default/gc/zen-select.css" rel="stylesheet" type="text/css" /><link class="user" href="/forums/sCSS/38.0/sprites/1477585684000/Theme3/default/gc/zen-componentsCompatible.css" rel="stylesheet" type="text/css" /><script src="/forums/jslibrary/1479750578000/sfdc/NetworkTracking.js" type="text/javascript"></script><script>try{ NetworkTracking.init('/forums/_ui/networks/tracking/NetworkTrackingServlet', 'network', '066F0000001KzEF'); }catch(x){}try{ NetworkTracking.logPageView();}catch(x){}</script><meta HTTP-EQUIV="PRAGMA" CONTENT="NO-CACHE" />
<meta HTTP-EQUIV="Expires" content="Mon, 01 Jan 1990 12:00:00 GMT" />

        
        <script src="//apis.google.com/js/plusone.js"></script>
        <script defer="defer" src="//platform.twitter.com/widgets.js"></script>
        <script src="//connect.facebook.net/en_US/all.js#xfbml=1&amp;appId=100816963337586"></script>
        <script src="//ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>

        
        <link href="/resource/stylesheets/syntax-highlighter.min.css" rel="stylesheet" type="text/css" />
        <script src="/resource/javascripts/syntax-highlighter.min.js"></script>

        <meta content="DeveloperForce" property="og:title" />
        <meta content="article" property="og:type" />
            <meta content="https://dfc-org-production.force.com/forums/?id=906F00000008pc4IAA" property="og:url" />
        <meta content="//res.cloudinary.com/hy4kyit2a/image/upload/sd_social300x300_1.png" property="og:image" />
        <meta content="DeveloperForce.com" property="og:site_name" />

        

        <style type="text/css">


            /* this is to copy to styles_min_7.css to fix an issue in search-query box SIZE, that does not appear in firebug or similar but need to be set */
            header .navbar .navbar-search .search-query {
                -moz-box-sizing: content-box;
                box-sizing: content-box;
            }
            /**/

            /* this is to overwrite the ChatterAnswers.css .facebook class */
            header .navbar .social-media .facebook{
                padding-left: 0px;
            }
            /**/

            /* this is to add a z-index property to the 'X' delete btn in comments */
            .csfeedcontainer .csdisableddelete, .csfeedcontainer .cxdeletelink {
                z-index: 9999;
            }

            .csfeedcontainer a {
                color: #048ec6 !important;
            }


            /* this is to fix an issue with nowrap in code tags */
            .feeditemcontent code {
                white-space: normal !important;
            }

            .csfeedcontainer .cxquestionheader .feeditemtext{
                margin-right: 0px !important;
            }


            /******** General styles *********/
            .datacategorylinks h3{
                color: #666;
                font-weight: normal;
                font-size: 16px;
                margin-bottom: 15px;
            }

            .datacategorylinks .csChildOption a {
                text-decoration: none;
                color: #048ec6;
                font-weight: bold;
                font-size: 13px;
                padding-left: 0;
            }
            .cacategorycounter{
                color: #555;
                font-weight: normal;
            }
            .datacategorylinks li a{
                color: #048ec6;
                padding: 0;
            }
            .cacategoymorelink li a{
                color: #048ec6;
                padding: none;
            }
            .cacategoymorelink{
                text-decoration: none;
                font-weight: bold;
                color: #048ec6;
                font-weight: bold;
                font-size: 13px;
            }
            .caleftnavseparator{
                width:100%;
                border-bottom: 1px solid #CCC;
                margin: 15px 0;
                clear: both;
            }
            #cs\:profile{
                float: left;
                margin: 0 0 10px;
            }
            #cs\:profile .username{
                display: none;
                /*margin-top: 10px;
                font-size: 13px !important;
                color: #0040ac;
                font-weight: bold;*/
            }
            .usericon, #cs\:profile .usericon {
                top: 100% !important;
                box-shadow: none;
                position: relative;
                margin-left: 0;
                padding-right: 15px;
            }
            .usericon .chatter-avatarStyle {
                display: none;
            }
            .usericon img {
                height: 27px;
                width: 27px;
            }
            .usericon {
                height: 27px;
                width: 27px;
            }
            .feeditemcommentbody{
                display: none !important;
            }
            .csCompanyNameTag{
                display: none;
            }
            .agentIcon{
                display: none;
            }
            .csfeedcontainer .feeditem {
                border: 1px solid #E8E8E8;
                padding: 0;
            }
            .feedcommentarrow{
                display: none !important;
            }
            .cxcomments .feeditemcomments{
                border: 1px solid #E8E8E8;
                padding: 20px 0;
            }
            .cxaddcommentaction{
                display: none;
            }
            .feeditemseparatingdot{
                display: none;
            }
            .csfeedcontainer .feeditem{
                box-shadow: -1px 2px 3px #b8b8b8 !important;
            }
            .csfeedcontainer .hideContext .csPreviewLinkContainer{
                display: none;
            }
            .csPreviewLinkContainer{
                display: none;
            }
            .showmorecommentscontainer{
                /*display: none;*/
            }
            .csfeedcontainer .feeditemcomment, .csfeedcontainer .feedcommentsshowmore, .feeditemcommentplaceholder, .csfeedcontainer{
                border: none;
            }
            .feeditembestreplyheader{
                margin: 5px 0 8px;
            }
            .feeditemcomment{
                padding: 0 8px;
            }
            .feeditemcomment .cxfeedcomment .cxfeedItemBestReplyText{
                width: 50%;
            }
            .cxsingleitemdetailfeed{
                color: #048ec6 !important;
                font-weight: normal !important;
            }
            .cxfeeditemcommentdot{
                display: none !important;
            }
            .csfeedcontainer .feeditemcontent {
                padding-left: 15px;
                padding-right: 0;
            }
            .prompt a{
                color: #048ec6 !important;
            }

            .cxSingleQuestionDetailFeed .feeditemcommentbody{
                display: block !important;
            }
            .cxSingleQuestionDetailFeed .feeditemcomment .usericon{
                width: 40px;
                height: 40px;
            }
            .cxSingleQuestionDetailFeed .feeditemcomment .usericon img{
                width: 40px;
                height: 40px;
            }

            .cxSingleQuestionResultFeed .feeditemcommentbody{
                display: block !important;
            }
            .cxSingleQuestionResultFeed .feeditemcomment .usericon{
                width: 40px;
                height: 40px;
            }
            .cxSingleQuestionResultFeed .feeditemcomment .usericon img{
                width: 40px;
                height: 40px;
            }

            .csfeedcontainer .feeditemcommentplaceholder input {
                color: #999999;
                height: 2.3em;
                min-height: 2.3em;
            }
            .cxSingleQuestionDetailFeed .cxcommentplaceholder input{
                border: 1px solid #e8e8e8;
                background: #ffffff;
                border-radius: 0;
            }
            .cxSingleQuestionDetailFeed .feeditemcomment{
                background: #ffffff;
                border-top: 1px solid #E8E8E8;
                padding: 25px 0 15px;
            }
            .cxSingleQuestionDetailFeed .cxfeedItemBestReplyText{
                background: #F0F8E2;
                padding-top: 10px;
                border: none;
            }
            /*.cxSingleQuestionDetailFeed .cxaddcommentaction{
                display: block;
                float: right;
            }*/
             .cxSingleQuestionDetailFeed .cxaddcommentaction{
                display: inline;
                margin: 0 2px 0 5px;
            }


            .cxSingleQuestionResultFeed .cxcommentplaceholder input{
                border: 1px solid #e8e8e8;
                background: #ffffff;
                border-radius: 0;
            }
            .cxSingleQuestionResultFeed .feeditemcomment{
                background: #ffffff;
                border-top: 1px solid #E8E8E8;
                padding: 25px 0 15px;
            }
            .cxSingleQuestionResultFeed .cxfeedItemBestReplyText{
                background: #F0F8E2;
                padding-top: 10px;
                border: none;
            }
            /*.cxSingleQuestionResultFeed .cxaddcommentaction{
                display: block;
                float: right;
            }*/
             .cxSingleQuestionResultFeed .cxaddcommentaction{
                display: inline;
                margin: 0 2px 0 5px;
            }
            .cxSingleQuestionDetailFeed .csBestReplyInSIV{
                display: none;
            }
            .cxSingleQuestionDetailFeed .feeditemcomments .header{
                display: none;
            }
            .cxSingleQuestionDetailFeed .feeditemfirstentity{
                margin-top: 19px;
            }
            .cxSingleQuestionDetailFeed .feeditemfooter{
                margin-left: 0px !important;
            }
            .cxSingleQuestionResultFeed .csBestReplyInSIV{
                display: none;
            }
            .cxSingleQuestionResultFeed .feeditemcomments .header{
                display: none;
            }
            .cxSingleQuestionResultFeed .feeditemfirstentity{
                margin-top: 19px;
            }
            .cxSingleQuestionResultFeed .feeditemfooter{
                margin-left: 0px !important;
            }


            .csMini .threecolumn {
                background: none;
                width: 1180px;
            }
            .threecolumn .leftContent{
                width: 220px;
                padding-left: 5px;
            }
            .threecolumn .centerContent{
                width: 920px;
            }

            .csMini .threecolumn .mainContent, .csMini .mainContent .lowerMainContent {
                float: left;
                width: 860px;
            }
            .threecolumn .mainContent {
                margin-left: 0;
            }
            .centerContent .csfeedcontainer {
                max-width: 920px;
            }
            /*.centerContent #cs\:searchAskForm.tbsearchAskForm {
                width: 721px;
            }*/
            .feeditemheader{
                color: #048ec6 !important;
                font-weight: normal;
            }
            .csfeedcontainer .cxquestionheader{
                margin-right: 0;
            }
            .csfeedcontainer .cxquestionheader .feeditemtext {
                margin-left: 15px;
                margin-right: 160px;
            }
            .cxSingleQuestionDetailFeed .cxquestionheader .feeditemtext{
                margin-left: 42px !important;
            }

            .cxSingleQuestionResultFeed .cxquestionheader .feeditemtext{
                margin-left: 42px !important;
            }


            .feeditemfooter{
                margin-left: 0;
                clear: both;
            }
            .cxSingleQuestionDetailFeed .feeditemfooter{
                margin-left: 42px;
            }


            .cxSingleQuestionResultFeed .feeditemfooter{
                margin-left: 42px;
            }


            .csMini #cs\:footer{
                display: none;
            }


            /**/
            .usericon{
                display: none;
            }
            #user_pic .usericon{
                display: block;
            }
            /**/


            .feeditemfirstentity{
                display: none;
            }

            .cxSingleQuestionDetailFeed .usericon{
                display: block;
            }
            .cxSingleQuestionDetailFeed .feeditemfirstentity{
                display: block;
            }


            .cxSingleQuestionResultFeed .usericon{
                display: block;
            }
            .cxSingleQuestionResultFeed .feeditemfirstentity{
                display: block;
            }


            .cxquestiontitlewithlink{
                margin-left: 0 !important;
            }
            .cxquestionbodypreview{
                margin-left: 0 !important;
            }
            .cxdeletelink {
                margin: 10px 0 0 0;
            }
            #cs:inlineSignIn{
                display: none;
                left: 72px !important;
            }
            .cxfooter{
                display: none;
            }
            .solved_container{
                display: block;
                float: right;
                text-align: center;
                margin: 15px 0 0 0;
                clear: both;
            }
            /*.solved_question{
                background: none repeat scroll 0 0 #009DDC;
                color: #FFFFFF;
                padding: 14px 18px;
            }*/
            .solved_question {
                background: none repeat scroll 0 0 #009DDC;
                border: 1px solid #327CBB;
                box-shadow: -1px 1px 2px #1963A2;
                color: #FFFFFF;
                margin-right: 5px;
                margin-bottom: 8px;
                padding: 14px 18px;
            }
            .solved_question_link:link, .solved_question_link:hover, .solved_question_link:visited{
                color: #FFFFFF;
                text-decoration: none;
            }
            .num_replies{
                color: #048ec6;
                padding-right: 8px;
            }
            .feeditemextras{
                display: none;
            }
            .cxSingleQuestionDetailFeed .feeditemextras{
                display: block;
            }


            .cxSingleQuestionResultFeed .feeditemextras{
                display: block;
            }


            .askContainer .tabs{
                height: 40%;
            }
            .leftContent .usericon{
                display: block;
            }
            #cs\:profile{
                padding-left: 0;
            }
            #cs\:profile .usericon{
                height: 40px;
                width: 40px;
            }
            #cs\:profile .usericon img {
                height: 40px;
                width: 40px;
            }
            .cxshowmorefeeditems{
                display: none;
            }
            .cxfollowlink{
                display: none;
            }
            .followCount{
                display: none !important;
            }
            .feeditemseparatingdot{
                visibility: hidden !important;
            }
            .cxquestionbodypreview{
                height: 60px;
                margin-left: 15px;
                overflow: hidden;
            }
            .cxquestionbodypreview p{
                margin: 0;
                line-height: 21px;
            }
            .cxSingleQuestionDetailFeed .cxquestionbodypreview{
                height: auto;
                overflow: inherit;
            }


            cxSingleQuestionResultFeed .cxquestionbodypreview{
                height: auto;
                overflow: inherit;
            }


            /*.cxSingleQuestionDetailFeed.cxcommentplaceholder{
                display: block !important;
            }*/
            .csoptimizequestion .cxquestiontitlewithlink, .csoptimizequestion h4.feeditemtext {
                margin-top: 0;
            }
            .custom_user_icon img{
                width: 25px;
                height: 25px;
            }
            .custom_user_icon{
                height: 25px;
                width: 25px;
                padding: 0 5px 0 0;
            }
            .user_profile_name{
                padding: 0 5px;
            }
            .user_profile_name a{
                text-decoration: none;
                font-weight: bold;
            }
            .searchContainer{
                background: none repeat scroll 0 0 #FFFFFF;
                border: 2px solid #E8E8E8;
                padding: 0 9px 4px;
            }
            .serviceCommunitySearchBox .searchbox {
                height: 43px;
                background-color: #E8E8E8 !important;
                border: none !important;
                border-radius: 0 !important;
            }
            .serviceCommunitySearchBox .searchtext{
                background: #e8e8e8 !important;
            }
            .serviceCommunityAskWidget .tabs {
                height: 5% !important;
            }
            .csfeedcontainer {
                line-height: 5px;
            }
            .cxmysettingslink{
                display: none !important;
            }
            /*.cxafterlike{
                display: none !important;
            }*/
            #forums_login_wrapper h3{
                font-size: 14px !important;
                line-height: 16px;
                margin-bottom: 0;
                color: #003FA9;
            }
            .csInfo{
                line-height: 16px;
            }
            #cs\:uploadLink{
                display: none !important;
            }
            #cs\:supportBubble{
                display: none !important;
            }
            .deflectionWrapper .filters{
                display: none;
            }
            .serviceCommunitySearchAskWidgetMain .msgbox{
                line-height: 28px;
            }
            .forums_social_media_container{
                float: right;
            }

            .forums_login_wrapper .forums_login{
                display: block;
                width: 118px;
                background: none repeat scroll 0 0 #FFFFFF;
                border: 1px solid #999;
                color: #2a97d4;
                padding: 10px 5px;
                text-decoration: none;
                background: #ffffff; /* Old browsers */
                background: -moz-linear-gradient(top,  #ffffff 0%, #e5e5e5 100%); /* FF3.6+ */
                background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,#ffffff), color-stop(100%,#e5e5e5)); /* Chrome,Safari4+ */
                background: -webkit-linear-gradient(top,  #ffffff 0%,#e5e5e5 100%); /* Chrome10+,Safari5.1+ */
                background: -o-linear-gradient(top,  #ffffff 0%,#e5e5e5 100%); /* Opera 11.10+ */
                background: -ms-linear-gradient(top,  #ffffff 0%,#e5e5e5 100%); /* IE10+ */
                background: linear-gradient(to bottom,  #ffffff 0%,#e5e5e5 100%); /* W3C */
                filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#ffffff', endColorstr='#e5e5e5',GradientType=0 ); /* IE6-9 */
            }
            .searchbutton .label{
                background: none;
            }

            .dont_have_account{
                font-size: 11px;
            }

            .signup_dev_edition{
                font-size: 11px;
                font-weight: bold;
                color: #048ec6;
            }

            .reg-sign-up_div{
                width: 162px;
                min-height: 25px;
                background-color: rgb(0,168,220);/* Old browsers */
                filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#00a8dc', endColorstr='#009aca',GradientType=0 ), dropshadow(color=#026786, offx=0, offy=-1); /* IE6-8 */
                background:url(data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiA/Pgo8c3ZnIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgd2lkdGg9IjEwMCUiIGhlaWdodD0iMTAwJSIgdmlld0JveD0iMCAwIDEgMSIgcHJlc2VydmVBc3BlY3RSYXRpbz0ibm9uZSI+CiAgPGxpbmVhckdyYWRpZW50IGlkPSJncmFkLXVjZ2ctZ2VuZXJhdGVkIiBncmFkaWVudFVuaXRzPSJ1c2VyU3BhY2VPblVzZSIgeDE9IjAlIiB5MT0iMCUiIHgyPSIwJSIgeTI9IjEwMCUiPgogICAgPHN0b3Agb2Zmc2V0PSIwJSIgc3RvcC1jb2xvcj0iIzAwYThkYyIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjQ5JSIgc3RvcC1jb2xvcj0iIzAwYThkYyIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjQ5JSIgc3RvcC1jb2xvcj0iIzAwOWFjYSIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjEwMCUiIHN0b3AtY29sb3I9IiMwMDlhY2EiIHN0b3Atb3BhY2l0eT0iMSIvPgogIDwvbGluZWFyR3JhZGllbnQ+CiAgPHJlY3QgeD0iMCIgeT0iMCIgd2lkdGg9IjEiIGhlaWdodD0iMSIgZmlsbD0idXJsKCNncmFkLXVjZ2ctZ2VuZXJhdGVkKSIgLz4KPC9zdmc+);
                background:-moz-linear-gradient(top,  rgba(0,168,220,1) 0%, rgba(0,168,220,1) 49%, rgba(0,154,202,1) 49%, rgba(0,154,202,1) 100%); /* FF3.6+ */
                background:-webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(0,168,220,1)), color-stop(49%,rgba(0,168,220,1)), color-stop(49%,rgba(0,154,202,1)), color-stop(100%,rgba(0,154,202,1))); /* Chrome,Safari4+ */
                background:-webkit-linear-gradient(top,  rgba(0,168,220,1) 0%,rgba(0,168,220,1) 49%,rgba(0,154,202,1) 49%,rgba(0,154,202,1) 100%); /* Chrome10+,Safari5.1+ */
                background:-o-linear-gradient(top,  rgba(0,168,220,1) 0%,rgba(0,168,220,1) 49%,rgba(0,154,202,1) 49%,rgba(0,154,202,1) 100%); /* Opera 11.10+ */
                background:-ms-linear-gradient(top,  rgba(0,168,220,1) 0%,rgba(0,168,220,1) 49%,rgba(0,154,202,1) 49%,rgba(0,154,202,1) 100%); /* IE10+ */
                background:linear-gradient(to bottom,  rgba(0,168,220,1) 0%,rgba(0,168,220,1) 49%,rgba(0,154,202,1) 49%,rgba(0,154,202,1) 100%); /* W3C */
                -webkit-border-radius:4px;
                border-radius:4px;
                -webkit-box-shadow: inset 0px 0px 0px 1px rgba(79, 195, 231, 1);
                box-shadow: inset 0px 0px 0px 1px rgba(79, 195, 231, 1);
                border:1px solid #0089b4;
                -moz-box-sizing: border-box;
                -webkit-box-sizing: border-box;
                box-sizing: border-box;
            }


            .reg-sign-up_div .cloudImg {
                background-image: url("//res.cloudinary.com/hy4kyit2a/image/upload/v1370270184/cv0c6vm49rfydoh4qpgv.png");
                float: left;
                height: 15px;
                width: 18px;
                margin: 4px 0 4px 10px;
            }

            .reg-sign-up_btn_div{
                width:122px;
                height:25px;
                float: right;
                -moz-box-sizing: border-box;
                -webkit-box-sizing: border-box;
                box-sizing: border-box;
                margin: 0 6px 0 0;
            }

            .reg-sign-up{
                font-family: ProximaNovaRegular;
                background-color: rgba(0, 0, 0, 0);
                background-color: transparent;
                margin: 0;
                padding: 0;
                font-weight: normal;
                font-style: normal;
                width:100%;
                height:25px;
                color:#ffffff;
                font-size:13px;
                border:0px;
                text-align: right;
                -moz-box-sizing: border-box;
                -webkit-box-sizing: border-box;
                box-sizing: border-box;
                text-shadow: 0px -1px 0px #0082a9;
            }

            .reg-sign-up_div:hover {
                filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#0285ad', endColorstr='#02799e',GradientType=0 ), dropshadow(color=#026786, offx=0, offy=-1); /* IE6-8 */

                background:rgb(2,133,173); /* Old browsers */
                /* IE9 SVG, needs conditional override of 'filter' to 'none' */
                background:url(data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiA/Pgo8c3ZnIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgd2lkdGg9IjEwMCUiIGhlaWdodD0iMTAwJSIgdmlld0JveD0iMCAwIDEgMSIgcHJlc2VydmVBc3BlY3RSYXRpbz0ibm9uZSI+CiAgPGxpbmVhckdyYWRpZW50IGlkPSJncmFkLXVjZ2ctZ2VuZXJhdGVkIiBncmFkaWVudFVuaXRzPSJ1c2VyU3BhY2VPblVzZSIgeDE9IjAlIiB5MT0iMCUiIHgyPSIwJSIgeTI9IjEwMCUiPgogICAgPHN0b3Agb2Zmc2V0PSIwJSIgc3RvcC1jb2xvcj0iIzAyODVhZCIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjQ5JSIgc3RvcC1jb2xvcj0iIzAyODVhZCIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjQ5JSIgc3RvcC1jb2xvcj0iIzAyNzk5ZSIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjEwMCUiIHN0b3AtY29sb3I9IiMwMjc5OWUiIHN0b3Atb3BhY2l0eT0iMSIvPgogIDwvbGluZWFyR3JhZGllbnQ+CiAgPHJlY3QgeD0iMCIgeT0iMCIgd2lkdGg9IjEiIGhlaWdodD0iMSIgZmlsbD0idXJsKCNncmFkLXVjZ2ctZ2VuZXJhdGVkKSIgLz4KPC9zdmc+);
                background:-moz-linear-gradient(top,  rgba(2,133,173,1) 0%, rgba(2,133,173,1) 49%, rgba(2,121,158,1) 49%, rgba(2,121,158,1) 100%); /* FF3.6+ */
                background:-webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(2,133,173,1)), color-stop(49%,rgba(2,133,173,1)), color-stop(49%,rgba(2,121,158,1)), color-stop(100%,rgba(2,121,158,1))); /* Chrome,Safari4+ */
                background:-webkit-linear-gradient(top,  rgba(2,133,173,1) 0%,rgba(2,133,173,1) 49%,rgba(2,121,158,1) 49%,rgba(2,121,158,1) 100%); /* Chrome10+,Safari5.1+ */
                background:-o-linear-gradient(top,  rgba(2,133,173,1) 0%,rgba(2,133,173,1) 49%,rgba(2,121,158,1) 49%,rgba(2,121,158,1) 100%); /* Opera 11.10+ */
                background:-ms-linear-gradient(top,  rgba(2,133,173,1) 0%,rgba(2,133,173,1) 49%,rgba(2,121,158,1) 49%,rgba(2,121,158,1) 100%); /* IE10+ */
                background:linear-gradient(to bottom,  rgba(2,133,173,1) 0%,rgba(2,133,173,1) 49%,rgba(2,121,158,1) 49%,rgba(2,121,158,1) 100%); /* W3C */
                cursor:pointer;


                -webkit-box-shadow: inset 0px 0px 0px 1px rgba(80, 171, 231, 1);
                box-shadow: inset 0px 0px 0px 1px rgba(80, 171, 231, 1);
                text-shadow: 0px -1px 0px #026786;
            }

            /******** Forums categories component *******/
            #forums_categories_wrapper table tr td{
                border-collapse: collapse;
                border-bottom: solid 1px #E8E8E8;
                padding: 12px 30px 12px 0;
                font-size: 12px;
            }

            #forums_categories_wrapper .t_header{
                font-size: 14px;
                font-weight: normal;
            }

            #forums_categories_wrapper .t_header td{
                color: #2a97d4;
            }

            #forums_categories_wrapper .t_label{
                font-size: 13px;
                font-weight: bold;
            }

            #forums_categories_wrapper .t_count{
                font-size: 14px;
            }
            .forums_categories_detail_title{
                font-size: 15px;
            }

            .prompt {
                background: #eff7fa;

            }

            #discussion_board_topbar{
                background-color: #92d5f0;
            }

            .discussion_board_container{
                width: 1170px;
                margin: 0 auto;
            }
            .discussion_board_container:after{
                clear: both;
                content: ".";
                display: block;
                height: 0;
                visibility: hidden;
            }

            #discussion_board_title {
                float: left;
                font-size: 35px;
                padding: 30px 0;
                color: #152134;
            }
            .beta_banner_and_link{
                width: 35%;
                font-size: 18px;
                padding: 34px 0 0 10px;
                float: left;
                color: #152134;
            }

            .beta_banner_and_link a{
                font-size: 15px
            }

            .floated_button {
                float: left;
                width: 100px;
            }

            .user_reputation_green{
                background-color: #3CBE7C !important;
            }

            .user_reputation_blue{
                background-color: #8EA6D8 !important;
            }

            .user_reputation_violet{
                background-color: #65619D !important;
            }

            .user_reputation_orange{
                background-color: #D7823F !important;
            }

            .user_moderator_badge {
                background-color: #000 !important;
                margin-left: 5px;
            }

            @media (max-width: 1040px) {
                .discussion_board_container {
                    width: 90%;
                }

                .serviceCommunitySearchResult .stats{
                    float:none !important;
                }
                .serviceCommunitySearchResult .timestamp{
                    float:none !important;
                    height:auto !important;
                }
            }

            @media (max-width: 1024px) {
                .beta_banner_and_link{
                    display: none;
                }

                .serviceCommunitySearchResult .stats{
                    float:none !important;
                }
                .serviceCommunitySearchResult .timestamp{
                    float:none !important;
                    height:auto !important;
                }
            }

            @media (max-width: 700px) {
                #discussion_board_title {
                    float: none;
                    padding: 20px 0;
                    line-height: 30px;
                }

                .serviceCommunitySearchResult .stats{
                    float:none !important;
                }
                .serviceCommunitySearchResult .timestamp{
                    float:none !important;
                    height:auto !important;
                }
            }

            /* Landscape phones and down */
            @media (max-width: 448px) {
                .floated_button {
                    float: left;
                    width: 90px;
                }
                .prompt{
                    left: 0px !important;
                }
                .serviceCommunitySearchResult .stats{
                    float:none !important;
                }
                .serviceCommunitySearchResult .timestamp{
                    float:none !important;
                    height:auto !important;
                }
            }

            .header_false{
                background-color: #023F5E;
                height: 80px;
            }
            
            
            #main_profile_container .left_section {
                padding: 0;
                width: 200px;
            }
            
            #main_profile_container{
                padding: 10px 0 0 0;
                margin: auto;
                background: #FFFFFF;
                width: 1170px;
            }
            
            
            
            @media (min-width: 950px) {
                .feeditemcontent .read-more-link {
                    position: absolute;
                }
            }
            
            @media (min-width: 1450px) {
                #main_profile_container {
                    width: 1170px;
                }
            
                .row-fluid .span9{
                    margin-left: 50px;
                }
            
                /*.row-fluid .span9 {
                    width: 668px;
                }*/
            }
            
            @media (max-width: 1450px) {
                #main_profile_container .left_section {
                    padding: 0px;
                    /*margin: 0 0 0 30px;*/
                }
                
                .user_social {
                    margin: 0 auto;
                    width: 200px;
                }
            }
            
            @media (min-width: 521px) and (max-width: 1450px) {
                
                .profile_questions_container #user_stats{
                    width: intrinsic;
                    width: -moz-fit-content;
                    margin: 0 auto;
                }
            }
            
            @media (max-width: 1199px) {
                #main_profile_container{
                    width: 940px;
                }
            
                #profile_questions_container {
                    width: 720px;
                    margin: 0 0 0 20px;
                }
            }
            
            
            /* Portrait tablet to landscape and desktop */
            @media (min-width: 768px) and (max-width: 1450px) {
            
                #main_profile_container {
                    /*width: 94%;*/
                }
            
                /*.profile_questions_container #user_stats ul li{
                    margin: 0px 5px 0px 5px;
                    width: 170px;
                }*/
            
                .profile_questions_container #user_stats ul li.user_stats1 {
                    -moz-box-sizing: border-box;
                    box-sizing: border-box;
                    margin: 0 5px 0 0;
                }
            
                /*.......*/
            
                .row-fluid .span9 {
                    /*margin-left: 10px;*/
                    /*width: 674px;*/
                }
            }
            
            
            @media (max-width: 979px){
                #profile_questions_container {
                    width: 100%;
                    margin: 0 0 0 0;
                    float: none;
                }
                
                .contentArea .user_stats{
                    margin-top: 5px;
                }
                
                #user_stats ul li:last-child {
                    margin: 5px 0 0 0px !important;
                }
                
                #profile_details_container > #user_pic {
                    float: left;
                    margin-right: 8px;
                    margin-bottom: 8px;
                }
            
                .user_stats_list_container{
                    float: left;
                    margin-right: 30px;
                }
                
                .userprofile-sidebar-down ul.inline {
                    display: flex;
                }
                
                .userprofile-sidebar-down ul.unstyled {
                    display: table;
                }
            
                #main_profile_container .left_section {
                    width: 100%;
                    float: none;
                }
            
                /*.discussion_board_container{
                    width: 100%;
                }*/
            
                #cs\:theFeed{
                    padding: 10px 0 0;
                    margin-top: 10px;
                }
            
                .csfeedcontainer {
                    padding-bottom: 0;
                }
            
                .csfeedcontainer .feeditem {
                    margin: 0 0 10px;
                }
            
                .csfeedcontainer .cxquestionheader .feeditemtext {
                    margin-right: 0px;
                }
            
                .cxPopularFeed .cxfeeditem .cxfeeditemcontent {
                    padding-left: 10px !important;
                    padding-right: 10px;
                }
            
                h4.cxquestiontitlewithlink{
                    margin-bottom: 0px;
                }
            
                .cxquestionheader .cxquestionbodypreview.feeditemtext {
                    margin-top: 0;
                }
            
                .row-fluid .span9{
                    float: none;
                    margin: 0 auto;
                    clear: both;
                }
                
                .edit_profile_table{
                    margin: 0 auto;
                }
            }
            
            @media (min-width: 768px) and (max-width: 979px) {
                /* here */
                /*.discussion_board_container{
                    width: 750px;
                }*/
            
                /* HERE */
            
                #main_profile_container {
                    width: 96%;
                }
            }
            
            /* Landscape phone to portrait tablet */
            @media (min-width: 521px) and (max-width: 767px){
                #main_profile_container {
                    width: 94%;
                }
            
                .csMini .threecolumn .mainContent{
                    margin-left: 0px;
                }
            
                /*.discussion_board_container{
                    width: 974px;
                }*/
            
                .profile_questions_container #user_stats ul li .stats_number {
                    /*font-size: 20px;
                    line-height: 20px;*/
                }
            
                .profile_questions_container #user_stats ul li .stats_text {
                    /*font-size: 12px;
                    line-height: 12px;*/
                }
            
                .row-fluid .span9{
                    width: auto;
                }
            
                .profile_questions_container #user_stats{
                    width: 100%;
                }
            
                .profile_questions_container #user_stats ul li{
                    width: 20%;
                    margin: 0px 1% 0px 0px;
                    -moz-box-sizing: border-box;
                    box-sizing: border-box;
                }
            
                .profile_questions_container #user_stats ul li.user_stats1 {
                    width: 37%;
                    max-width: 37%;
                    margin: 0px 1% 0px 0px;
                    -moz-box-sizing: border-box;
                    box-sizing: border-box;
                }
            
                .profile_questions_container #user_stats ul li.user_stats:last-child {
                    margin: 0;
                }
            }
            
            
            @media (max-width: 658px){
            
            }
            
            
            /* Landscape phones and down */
            /* the real value is 448 but I need to set this in 520 */
            @media (max-width: 520px) {
            
                #main_profile_container {
                    width: 94%;
                }
            
                .row-fluid .span9{
                    width: auto;
                }
            
                .profile_questions_container #user_stats ul li{
                    /*width: 129px;
                    margin: 0px 5px 0px 0px;*/
                    margin: 0 1% 0 0;
                    width: 32%;
                    -moz-box-sizing: border-box;
                    box-sizing: border-box;
                }
            
                .profile_questions_container #user_stats ul li:last-child{
                    max-width: 35%;
                    min-width: 34%;
                    margin: 0;
                }
            
                .profile_questions_container #user_stats ul li.user_stats1{
                    width: 100%;
                    max-width: 100%;
                    -moz-box-sizing: border-box;
                    box-sizing: border-box;
                    margin: 0px 0px 3px 0px;
                    height: 48px;
                }
            
                /*.profile_questions_container #user_stats ul li .stats_number {
                    font-size: 20px;
                    line-height: 20px;
                }*/
            
                /*.profile_questions_container #user_stats ul li .stats_text {
                    font-size: 12px;
                    line-height: 12px;
                }*/
            }
            
            #navigation-bar h1 {
                font-size: 28px !important;
            }
        </style>

        <script>

            $( document ).ready(function() {
                if( $('div[id$="inlineSignIn"]').lenght != -1 ){
                    $('a[id$="inlineSignUpButton"]').click(function(){
                        document.location.href='/signup?d=70130000000tgM8';
                    });
                }
                if( $('div[id$="inlineSignIn"]').lenght != -1 ){
                    $('a[id$="inlineSignInButton"]').click(function(event){
                        event.preventDefault();
                        var href = window.location.href;
                        var index = href.indexOf('id=');
                        var id = href.substring(index);
                        var ref = '/forums/ForumsMain?'+ id;
                        document.location.href='/forums/CommunitiesLogin?startURL='+ ref;
                    });
                }


                var changeSignUpInterval;
                if( $('#searchInput').lenght != -1 ){
                    $('#searchInput').change(function(){
                        changeSignUpInterval = setInterval(function(){changeSignUpBtnLink()}, 100);
                    });
                }

                function changeSignUpBtnLink(){
                    if( $("a:contains('Sign Up')", $('.signinbox')).lenght != -1 ){

                        if( $("a:contains('Sign Up')", $('.signinbox')).is(':visible') ){

                            $("a:contains('Sign Up')").unbind();
                            $("a:contains('Sign Up')").click(function(){
                                document.location.href='/signup?d=70130000000tgM8';
                                $('#auraErrorMessage').hide();
                            });

                            clearInterval(changeSignUpInterval);
                        }
                    }
                }
            });
            
        </script><!--<dfc-head>-->

  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">

<link rel="icon" href="/resources2/favicon.ico" type="image/x-icon">
<link rel="shortcut icon" href="/resources2/favicon.ico" type="image/x-icon">
  <meta property="og:image" content="https://res.cloudinary.com/hy4kyit2a/image/upload/og-image.jpg" />
<link rel="stylesheet" type="text/css" href="/resources2/stylesheets/dsc-default-font.css?sv=18"/>

  <link href="//res.cloudinary.com/hy4kyit2a/image/upload/v1428517247/iphone_3_j0mhil.png" rel="apple-touch-icon-precomposed" type="image/png" />
  <link href="//res.cloudinary.com/hy4kyit2a/image/upload/v1428517247/iphone_3_j0mhil.png" rel="apple-touch-icon-precomposed" sizes="72x72" type="image/png" />
  <link href="//res.cloudinary.com/hy4kyit2a/image/upload/v1428517258/iphone-retina_ogf4ll.png" rel="apple-touch-icon-precomposed" sizes="114x114" type="image/png" />
  <link href="//res.cloudinary.com/hy4kyit2a/image/upload/v1428517265/ipad-retina_h8t1cu.png" rel="apple-touch-icon-precomposed" sizes="144x144" type="image/png" />


    <link href='/resource/stylesheets/holygrail.min.css' rel='stylesheet' type='text/css'/>
    <link rel="stylesheet" type="text/css" href="/resources2/stylesheets/dsc-default-font.css?sv=18"/>
<script type='text/javascript' src='/resource/javascripts/holygrail.min.js'></script>

<style>
    
</style>

<!--</dfc-head>-->
                    <link href="https://developer.salesforce.com/forums/?id=906F00000008pc4IAA" rel="canonical" />
                    <title>What does the "%2F" characters mean when used before an object in a URL? - Salesforce Developer Community</title>
                
                <script type="text/javascript">
                    var is_loggedin = false;
                    var is_moderator = false;
                    //Keep track of feed refresh to avoid multiple calls while scrolling
                    var feed_refresh_on = false;

                    Ext.onReady(function(){
                        drawSolvedReplies();
                        addReadMoreLink();
                        changeAnswerActionLabel();
                        changeQuestionSearchPlaceholder();
                        $("pre").addClass('syntaxhighlighter brush: VisualForce;');
                        runHighlighter();



                        Sfdc.on(chatterService.getFeed(), "chatterService:afterFeedRefresh", drawSolvedReplies);

                        //Sfdc.on(chatterService.getFeed(), "chatterService:afterFeedRefresh", updateFeedLinks );

                        //Sfdc.on(chatterService.getFeed(), "chatterService:afterFeedRefresh", changeSocialData);

                        Ext.Ajax.on('requestcomplete', function(conn,response,opts){
                            unfollow(opts);
                            task.delay(100);
                            task.delay(300);
                             //Adding css class for syntaxHighlighter after 300 ms
                            setTimeout(function(){
                                $("pre").addClass('syntaxhighlighter brush: VisualForce;');
                                runHighlighter();

                            },300);
                            //Init tootlip if user logged out
                            console.log('is_loggedin = '+is_loggedin);
                            if(!is_loggedin){
                                setQtip($('#discussion_button'), $('#login_prompt_button'));
                                $('#searchInput').prop('readonly',true);
                                $('.searchbutton.uiButton').attr('readonly',true);
                                setSearchQuestionField(0);
                            }
                            $('#searchQuestion').slideDown();
                        }, this);

                        // Follow a question after posting a reply
                        Ext.getBody().on('click', function (e) {
                            if (Ext.DomQuery.select('.cxunfollowlink').length === 0) {
                                followQuestionCallback(e.browserEvent);
                            }
                        }, this, {delegate: '.newcommentbutton.cxnewpublicreply'});

                        // Follow a question after clicking "Like"
                        $('.cxusefullink').live('click', function (e) {
                            followQuestionCallback(e);
                            return false;
                        });

                        var current_item;
                        $('.moderation_arrow').live('click', function(e){
                            current_item = $(e.target);
                            $(e.target).parent().parent().parent().parent().css('z-index', '500');
                            $(e.target).next('.moderation_dropdown').css('z-index', '2000');
                            $(e.target).next('.moderation_dropdown').show();
                        });

                        $(document).mouseup(function (e){
                            $(current_item).parent().parent().parent().parent().css('z-index', '0');
                            var container = $('.moderation_dropdown');

                            if (!container.is(e.target) && container.has(e.target).length === 0){
                                container.hide();
                            }
                        });

                        //Start a discussion button click listener
                        $('#discussion_button').click(function(){
                            if(is_loggedin){
                                var event = $A.get("e.serviceCommunity:proceedToPost");
                                    event.setParams({
                                    searchAskState: 2,
                                    query: "",
                                    guestUser: false
                                });
                                event.fire();
                            }else{
                                //Show login prompt
                            }
                        });
                    });

                    function setSearchQuestionField(count){
                      if($('#searchInput').length > 0){
                        setQtip($('.serviceCommunitySearchAskWidgetMain'), $('#login_prompt_search'));
                      }
                      else{
                        if(count<20){
                          setTimeout(setSearchQuestionField(count+1), 1500);
                        }
                      }
                    }
                    function setQtip(element, content_element){
                      element.qtip({
                        content: {
                            text: content_element.html()
                        },
                        position: {
                        my: "top center",
                            at: "bottom center"
                        },
                        style: {
                            classes: "qtip-df qtip-shadow qtip-rounded"
                        },
                        show: {event: 'click'},
                        hide: {event: "unfocus"}
                      });
                    }

                    var cookie_filters = '';
                    $(function () {

                        // Using jQuery's DOM-ready because of Ext's DOM-ready event being fired too late
                        // (maybe due to some AJAX request)



                        changeAnswerActionLabel();
                        if(is_moderator){
                            loadModerationDropdown();
                        }

                        $('.feedfilters li').click(function(){
                            setPreferredFilter($(this).find('a').attr('href'));
                        });

                        $('.feedsortby li').click(function(){
                            setPreferredFilter($(this).find('a').attr('href'));
                        });

                        var data_category;
                        var data_category_match = window.location.hash.match(/dc=(\w*)/);
                        typeof data_category_match == 'undefined' || data_category_match==null ? data_category = '' : data_category = data_category_match[0] + '&';

                        if(($.trim(cookie_filters) !== '') && !(/feedtype=SINGLE_QUESTION_DETAIL/.test(window.location.hash)) && ($('.cxthefeed').find('.cxSingleQuestionDetailFeed').length == 0) && ($('.cxthefeed').find('.cxSingleQuestionResultFeed').length == 0)) {
                            window.location.hash = '#!/' + data_category + cookie_filters;
                        } else if ($(".csfeedcontainer.cxSingleQuestionDetailFeed").size() == 0 && window.location.hash == '') {
                            window.location.hash = '#!/' + data_category + 'feedtype=RECENT&criteria=ALLQUESTIONS&';
                        }
                        navbar();

                        setNoFollowToLinks();
                    });

                    //Parses all ckeditor pre tags and changes the class to 'brush: VisualForce'
                    /*function parse_ckeditor_highlighter(){
                        jQuery.each($(".feeditemtext"), function(index,element){
                            var currentBody = $(element).html();
                            var reg = /(<pre ?.*?>)([\s\S]*?)(<\/pre>)/g
                            var matches = [];
                            var match;
                            while(match = reg.exec(currentBody)){
                                var auxmatch1 = match[1];
                                auxmatch1 = '<pre class="brush: VisualForce">';
                                currentBody = currentBody.replace(match[0], auxmatch1+match[2]+match[3]);
                                $(element).html(currentBody);
                            }
                        });
                    }*/

                    function unfollow(object) {
                        var url = object.url;
                        if(url && url.indexOf('Up') > 0) {
                            var id = url.substring(url.indexOf('vote/') + 5, url.indexOf('/Up'));
                            var nodeId = 'cx' + id.substring(0,15);

                            $('.' + nodeId) .find('.cxfollow').attr('title','Unfollow this question to stop receiving email updates');

                            $('.' + nodeId) .find('.cxfollow .cxfollowlink')
                                            .addClass('cxunfollowlink')
                                            .removeClass('cxfollowlink')
                                            .text('Unfollow')
                                            .show();

                            $('.' + nodeId) .find('.cxfollow .cxfollowing')
                                            .addClass('cxunfollowing')
                                            .removeClass('cxfollowing')
                                            .text('Unfolow');

                        }
                    }

                    function unescapePreTag(){
                        jQuery.each($(".feeditemtext"), function(index,element){
                            var currentBody = $(element).html();
                            var has_match = false;
                            var reg = /(&lt;pre ?.*?&gt;)(.*?)(&lt;\/pre&gt;)/g;
                            var matches = [];
                            var match;
                            while (match = reg.exec(currentBody)) {
                                var auxmatch1 = match[1];
                                var auxmatch3 = match[3];
                                auxmatch1 = auxmatch1.replace('&lt;', "<");
                                if(auxmatch1.indexOf('VisualForce')==-1){
                                    auxmatch1 = '<pre class="brush: VisualForce">';
                                }
                                auxmatch1 = auxmatch1.replace('&gt;', ">");
                                auxmatch3 = auxmatch3.replace('&lt;', "<");
                                auxmatch3 = auxmatch3.replace('&gt;', ">");
                                currentBody = currentBody.replace(match[0],auxmatch1+match[2]+auxmatch3);
                                has_match = true;
                            }
                            if(has_match){
                                currentBody = currentBody.replace(/<br>/g, "\n");
                                currentBody = currentBody.replace(/<br\/>/g, "\n");
                            }
                            $(element).html(currentBody);
                        });


                        jQuery.each($(".feedcommenttext"), function(index,element){
                            var currentBody = $(element).html();
                            var has_match = false;
                            var reg = /(&lt;pre ?.*?&gt;)(.*?)(&lt;\/pre&gt;)/g;
                            var matches = [];
                            var match;
                            while (match = reg.exec(currentBody)) {
                                var auxmatch1 = match[1];
                                var auxmatch3 = match[3];
                                auxmatch1 = auxmatch1.replace('&lt;', "<");
                                if(auxmatch1.indexOf('VisualForce')==-1){
                                    auxmatch1 = '<pre class="brush: VisualForce">';
                                }
                                auxmatch1 = auxmatch1.replace('&gt;', ">");
                                auxmatch3 = auxmatch3.replace('&lt;', "<");
                                auxmatch3 = auxmatch3.replace('&gt;', ">");
                                currentBody = currentBody.replace(match[0],auxmatch1+match[2]+auxmatch3);
                                has_match = true;
                            }
                            if(has_match){
                                currentBody = currentBody.replace(/<br>/g, "\n");
                                currentBody = currentBody.replace(/<br\/>/g, "\n");
                            }
                            $(element).html(currentBody);
                        });
                    }

                    function changeSocialData(text){
                        //var url ='//'+window.location.host+'/forums';
                        //var question_id = window.location.hash.match('[?&]id=([^&]+)') == null ? null : window.location.hash.match('[?&]id=([^&]+)')[1];
                        //if(question_id!=null && question_id!=''){
                        //  url = url + '/?id='+question_id;
                        //}
                        //$('#discussion_board_socialData .addthis_toolbox').attr('addthis:url', url);
                    }

                    var first_load = true;
                    function drawSolvedReplies(){
                        redraw_navbar();
                        if(is_moderator){
                            loadModerationDropdown();
                        }
                        jQuery.each($('.user_profile_name'), function(index, value){
                            var current_hostname = window.location.hostname;
                            var ahref = $(value).find('a');
                            var loc = document.createElement("a");
                            loc.href = $(ahref).attr('href');
                            loc.hostname = current_hostname;
                            $(ahref).attr('href', loc.href);

                        });
                        if(($('.cxthefeed').find('.cxSingleQuestionDetailFeed')==null || $('.cxthefeed').find('.cxSingleQuestionDetailFeed').length===0) && ($('.cxthefeed').find('.cxSingleQuestionResultFeed')==null || $('.cxthefeed').find('.cxSingleQuestionResultFeed').length===0)){
                            $('.cxfeeditemcontent').each(function(index, element){
                                window.document.title = 'Salesforce Developer Community';
                                var replies = 0;
                                if($(element).find('.num_replies')==null || $(element).find('.num_replies').length===0){

                                    //User image
                                    var user_icon = $(element).find(".usericon img").filter(":first");
                                    //User name
                                    var name = $(element).find('.feeditemfirstentity').html();
                                    //Container where the the two previous items will be apended
                                    var user_info = $(element).find('.feeditemfooter');

                                    //Prepend user picture and name to footer
                                    $(user_info).prepend(
                                        jQuery('<li>').append(
                                            jQuery('<div>')
                                                .addClass('user_profile_name')
                                                .append(name)
                                        )
                                    ).prepend(
                                        jQuery('<li>').append(
                                            jQuery('<div>')
                                                .addClass('custom_user_icon')
                                                .append(user_icon)
                                        )
                                    );

                                    var hash = $(element).find(".cxshowmorecomments").attr("data-scc");
                                    hash = "(" + hash + ")";
                                    hash = eval(hash);

                                    if(typeof hash === "undefined"){
                                        //console.info('hash undefined');
                                        if($(element).find('.cxbestReply').length > 0){
                                            replies = replies + 1;
                                        }
                                    }else{
                                        replies = hash.totalReplies;
                                    }

                                    var isSolved = false;
                                    if($(element).find('.feeditembestreplyheader').length>0){
                                        isSolved = true;
                                    }

                                    var html = $(element).find('.feeditemfirstentity');
                                    var title_link = $(element).find('.cxquestiontitlewithlink').find('.cxsingleitemdetailfeed').attr('href');

                                    var container = jQuery('<div>').addClass('solved_container');
                                    if(isSolved){
                                        container.append(
                                            jQuery('<a>').attr({"href" : title_link, "class" : "solved_question_link"}).append(
                                                jQuery('<div>').addClass('solved_question').append(
                                                    'SOLVED'
                                                )
                                            )
                                        );
                                    }
                                    container.append(
                                        jQuery('<a>').attr({href: title_link}).append(
                                            jQuery('<div>').addClass('num_replies').append(replies +' replies')
                                        )
                                    );
                                    html.after(container);

                                }

                            });
                            $('.feeditemextras').remove();
                            changeSocialData('#SalesforceDevs Discussion Forums - Q&A site for Salesforce admins, developers, architects & anybody in-between:');
                        }else{
                            window.document.title = $('.feeditemheader').text() + ' - Salesforce Developer Community';
                            changeSocialData('Can you answer this? ' + $('.feeditemheader').text() + ': (#SalesforceDevs)');
                            runHighlighter();
                        }
                        //ckeditor_to_syntax_highlighter();
                        changeAnswerActionLabel();
                        addReadMoreLink();
                        feed_refresh_on = false;
                        setNoFollowToLinks();
                        updateFeedLinks();
                        enableReplyArea();

                    }

                    function setNoFollowToLinks(){
                        // Adds nofollow value to rel attribute on every post containing links.
                        $('.cxthefeed div.feeditemtext.cxquestionbodypreview a').attr('rel','nofollow');
                        $('.cxthefeed div.feeditemcommentbody .feedcommenttext a').attr('rel','nofollow');
                        $('.cxthefeed').find('div.cxnotchatterlikesiv a').attr('rel','nofollow');
                    }

                    function updateFeedLinks(){

                      var userLink = $('.feeditemfirstentity a, .user_profile_name a');
                      var url = userLink.attr('href');
                      var splitUrl = url.split('forums');
                      url = location.origin + '/forums' + splitUrl[1];
                      userLink.attr('href',url);

                    }

                    function enableReplyArea(){
                        if(false){
                            $('.cxcommentplaceholderaction').click();
                        }
                    }

                    function changeAnswerActionLabel() {
                        $('.feeditem a.cxaddcommentaction').text('Reply');
                    }
                    function changeQuestionSearchPlaceholder() {
                        $('#searchInput').attr('Placeholder', 'Search or Ask a question to begin a discussion');
                    }

                    function getParameterByName(name) {
                        name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
                        var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
                            results = regex.exec(location);
                        return results === null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
                    }

                    function addReadMoreLink() {
                        $('.read-more-link').remove();

                        $('.feeditemtext.cxquestiontitlewithlink').each(function () {
                            var questionHref = $(this).find('a').attr('href');

                            var footer = $(this).closest('.feeditem').find('.feeditemfooter');

                            newReadMoreLinkNode(questionHref).appendTo(footer);
                        });
                    }

                    function newReadMoreLinkNode(questionHref) {
                        return jQuery('<li>')
                                    .append(jQuery('<a>').addClass('read-more-link').attr('href', questionHref).append('Continue reading or reply'));
                    }

                    // Traverses up the DOM from 'element' until the first .feeditem, and fetches feedItemId
                    function getQuestionId(element) {
                        var questionId = $(element).closest('.feeditem').data('scc').match("feedItemId:'([^']+)'");

                        return (questionId && questionId[1]) ? questionId[1] : null;
                    }

                    // Start following question
                    function followQuestion(id) {
                        $.get('/forums/forums_follow_post', {questionId: id})
                            //.success (function () {
                            //    // successful following question
                            //})
                            //.fail(function () {
                            //    // failed following question
                            //});
                    }

                    // Callback for events that require 'follow question' functionality
                    function followQuestionCallback(e){
                        var question_id = getQuestionId(e.target);

                        if (question_id) {
                            followQuestion(question_id)
                        }
                    }

                    /*function ckeditor_to_syntax_highlighter(){
                        parse_ckeditor_highlighter();
                        SyntaxHighlighter.highlight();
                    }*/

                    function runHighlighter(){
                        if( $('.bar', '.syntaxhighlighter').length > 0) {
                            SyntaxHighlighter.all();
                        }else{
                            unescapePreTag();
                            SyntaxHighlighter.config.clipboardSwf = '/resource/flash/clipboard.swf';
                            SyntaxHighlighter.highlight();
                        }
                    }

                    var task = new Ext.util.DelayedTask(function(){
                        drawSolvedReplies();
                    });

                    //Admin functions
                    function delete_post(question_id){
                        if(window.confirm("Are you sure you want to delete this post?")){
                            $.ajax({
                                type: 'GET',
                                url: '/forums/forums_delete_post',
                                data: {id: question_id}
                            }).done(function (data, status, xhr){
                                var question_card = $('.cx'+question_id.substring(0,15)+'.cxfeeditem');
                                question_card.fadeOut(500,
                                    function(){
                                        if($('.cxSingleQuestionDetailFeed').length===0){
                                            question_card.remove();
                                        }else{
                                            window.location.href='/forums';
                                        }
                                    });
                            });
                        }
                    }

                    function delete_reply(reply_id){
                        if(window.confirm("Are you sure you want to delete this reply?")){
                            $.ajax({
                                type: 'GET',
                                url: '/forums/forums_delete_reply',
                                data: {id: reply_id}
                            }).done(function (data, status, xhr){
                                var reply_div = $('.cx'+reply_id.substring(0,15)+'.feeditemcomment');
                                reply_div.fadeOut(500,
                                    function(){
                                        reply_div.remove();
                                    });
                            });
                        }
                    }

                    function change_category(question_id, category_name){
                        if(window.confirm("Are you sure you want change this post category?")){
                            $.ajax({
                                type: 'GET',
                                url: '/forums/forums_change_category',
                                data: {id: question_id, category: category_name}
                            }).done(function (data, status, xhr){
                                alert('Category changed');
                                $('#categories_modal').modal('hide');
                                if($('.cxSingleQuestionDetailFeed').length===0){
                                    window.location.reload();
                                }else{
                                    window.location.href='/forums?id='+question_id;
                                }
                            });
                        }
                    }

                    function list_datacategories(){
                        var dc_links = $('.cxdatacategory');
                        var list = [];
                        $.each(dc_links, function(index, value){
                            list[index] = $(value).data('dc');
                        });
                        list.sort();
                        return list;
                    }

                    function show_category_modal(question_id){
                        var categories = list_datacategories();
                        var container = jQuery('<div>').append(
                                            //jQuery('<h3>').text('Select a category')
                                        );
                        var list = jQuery('<ul>').addClass('categories_list');
                        $.each(categories, function(index, value){
                            list.append(
                                jQuery('<li>').append(
                                    jQuery('<a>').attr('href', 'javascript:change_category(\''+question_id+'\', \''+value+'\')').text(value.replace(/_/g, ' '))
                                )
                            );
                        });
                        container.append(list);
                        $('#categories-modal-body').html($(container));
                        $('#categories_modal').modal('show');
                    }

                    function loadModerationDropdown(){
                        /* Need to differentiate between question and comments to build
                            the dropdown with the right options for each one.
                        */
                        var questions = $('.cxfeeditem');
                        var comments = $('.cxfeedcomment');
                        var question_id = '';
                        $.each(questions, function(index, value){
                            //Build dropdown with change category
                            question_id = $(value).data('scc').match("feedItemId:'([^']+)'")[1];
                            if($('.cxthefeed').find('.cxSingleQuestionDetailFeed').length>0 && first_load){
                                first_load = false;
                                var replaceable_element = $(value).find('.cxreportabuseaction').filter(':first');
                                var f = buildModerationDropdown(replaceable_element, question_id, true);
                                $(replaceable_element).replaceWith(f);
                            }else{
                                if($('.cxthefeed').find('.cxSingleQuestionDetailFeed').length==0){
                                    first_load = true;
                                    var replaceable_element = $(value).find('.cxreportabuseaction').filter(':first');
                                    var f = buildModerationDropdown(replaceable_element, question_id, true);
                                    $(replaceable_element).replaceWith(f);
                                }
                            }
                        });

                        $.each(comments, function(index, value){
                            //Build dropdown without change category
                            var reply_id = $(value).data('scc').match("feedItemId:'([^']+)'")[1];
                            var replaceable_element = $(value).find('.cxreportabuseaction');
                            var f = buildModerationDropdown(replaceable_element, reply_id, false);
                            $(replaceable_element).replaceWith(f);
                        });

                    }

                    function buildModerationDropdown(value, question_id, is_question){
                        var dropdown = jQuery('<li>').addClass('moderation_item').append(
                                            jQuery('<a>').attr('href', 'javascript:void(0)').text('Moderate').addClass('moderation_arrow'));
                        var drop_list = jQuery('<ul>').addClass('moderation_dropdown');
                        var drop_item_1;
                        if(is_question){
                             drop_item_1 = jQuery('<li>').append(
                                            jQuery('<a>').attr('href', 'javascript:delete_post(\''+question_id+'\')').text('Delete')
                                        );
                            var drop_item_2 = jQuery('<li>').append(
                                                jQuery('<a>').attr('href', 'javascript:show_category_modal(\''+question_id+'\')').text('Change category')
                                            );
                            drop_item_2.appendTo(drop_item_1);
                        }else{
                            drop_item_1 = jQuery('<li>').append(
                                            jQuery('<a>').attr('href', 'javascript:delete_reply(\''+question_id+'\')').text('Delete')
                                        );
                            //if($('.cxthefeed').find('.feeditembestreplyheader').length===0){
                                var drop_item_3 = jQuery('<li>').append(
                                                    jQuery('<a>').attr('href', '/forums/forums_best_answer?id='+question_id).text('Best answer')
                                                );
                                drop_item_3.appendTo(drop_item_1);
                            //}
                        }
                        drop_list.append(drop_item_1).appendTo(dropdown);
                        return dropdown;
                    }

                    function setPreferredFilter(filter_params){
                        $.ajax({
                            type: 'GET',
                            url: '/forums/ForumsSetFiltersCookie',
                            data: {filters: filter_params}
                        }).done(function (data, status, xhr){
                            //console.info('Done setting the cookie');
                        });
                    }

                    function redraw_navbar(){
                        var title = '#SalesforceDevs Discussion Forums - Q&A site for Salesforce admins, developers, architects & anybody in-between:';
                        //var question_tweet_text = 'Can you answer this? Portal login Apex code doesn\'t send password email: (#SalesforceDevs)';
                        var question_tweet_text = 'Can you answer this? ';

                        var url ='//'+window.location.host+'/forums';
                        var breadcrumbs = $($('#navigation-bar .span9')[0]).children().first();
                        if(($('.cxthefeed').find('.cxSingleQuestionDetailFeed')==null || $('.cxthefeed').find('.cxSingleQuestionDetailFeed').length===0) && ($('.cxthefeed').find('.cxSingleQuestionResultFeed')==null || $('.cxthefeed').find('.cxSingleQuestionResultFeed').length===0)){
                            var data_category_match = window.location.hash.match(/dc=(\w*)/)
                            if(typeof data_category_match != 'undefined' && data_category_match!=null && data_category_match[1]!='Developer_Forums'){
                                breadcrumbs.html(
                                    jQuery('<div>').addClass('show').append(
                                        jQuery('<a>').attr('href', '/').text('Home')
                                    ).append(
                                        '&#160;&#187;&#160;'
                                    ).append(
                                        jQuery('<a>').attr('href', '/forums').text('Discussion Forums')
                                    ).append(
                                        '&#160;&#187;&#160;'
                                    ).append(
                                        jQuery('<h1>').text(categories_name[data_category_match[1]])
                                    )
                                );

                                var params = '';
                                if(getParameterByName('dc') !=  '') {
                                    params = '?dc=' + getParameterByName('dc');
                                }

                                url = window.location.protocol + url + params;
                                $('link[rel="canonical"]').attr('href',url);
                            }else{
                                breadcrumbs.html(
                                    jQuery('<div>').addClass('show').append(
                                        jQuery('<a>').attr('href', '/').text('Home')
                                    ).append(
                                        '&#160;&#187;&#160;'
                                    ).append(
                                        jQuery('<h1>').text('Discussion Forums')
                                    )
                                );

                                var params = '';
                                if(getParameterByName('dc') !=  '') {
                                    params = '?dc=' + getParameterByName('dc');
                                }

                                url = window.location.protocol + url + params;
                                $('link[rel="canonical"]').attr('href',url);
                            }
                        }else{
                            breadcrumbs.html(
                                jQuery('<div>').addClass('show').append(
                                    jQuery('<a>').attr('href', '/').text('Home')
                                ).append(
                                    '&#160;&#187;&#160;'
                                ).append(
                                    jQuery('<a>').attr('href', '/forums').text('Discussion Forums')
                                ).append(
                                    '&#160;&#187;&#160;'
                                ).append(
                                    jQuery('<h1>').text($('.feeditemheader').text())
                                )
                            );
                            title = question_tweet_text + ' ' + document.title;
                            //var question_id = window.location.hash.match('[?&]id=([^&]+)') == null ? null : window.location.hash.match('[?&]id=([^&]+)')[1];
                            var question_id = window.location.href.match('[?&]id=([^&]+)') == null ? null : window.location.href.match('[?&]id=([^&]+)')[1];
                            if(question_id!=null && question_id!=''){
                                url =  window.location.protocol + url + '/?id='+question_id;
                                $('link[rel="canonical"]').attr('href',url);
                            }
                        }
                        addthis.update('share', 'url', url);
                        addthis.update('share', 'title', title);
                    }

                    function navbar(){
                        var title = '#SalesforceDevs Discussion Forums - Q&A site for Salesforce admins, developers, architects & anybody in-between:';
                        //var question_tweet_text = 'Can you answer this? Portal login Apex code doesn\'t send password email: (#SalesforceDevs)';
                        var question_tweet_text = 'Can you answer this? ';

                        var url ='//'+window.location.host+'/forums';
                        if (typeof(updateNavBar) == 'function') {
                            var element = $('#navigation-bar .span9')[0];
                            var breadcrumbs = [];

                            var hash;

                            breadcrumbs.push(
                            {
                                href: '/',
                                text: 'Home'
                            })

                            if(($('.cxthefeed').find('.cxSingleQuestionDetailFeed')==null || $('.cxthefeed').find('.cxSingleQuestionDetailFeed').length===0) && ($('.cxthefeed').find('.cxSingleQuestionResultFeed')==null || $('.cxthefeed').find('.cxSingleQuestionResultFeed').length===0)){
                                //breadcrumbs.push('Discussion Forums');
                                hash = {
                                    'nav-title': 'Discussion Forums'
                                };
                            }else{
                                title = question_tweet_text + ' ' + document.title;
                                hash = {
                                    'nav-title': encodeURI($('.feeditemheader').text())
                                };
                                breadcrumbs.push(
                                    {
                                        href: '/forums',
                                        text: 'Discussion Forums'
                                    }
                                );
                                //breadcrumbs.push('Question detail');

                                var question_id = window.location.hash.match('[?&]id=([^&]+)') == null ? null : window.location.hash.match('[?&]id=([^&]+)')[1];
                                if(question_id!=null && question_id!=''){
                                    url = url + '/?id='+question_id;
                                }

                        //}
                            }

                            hash['show-breadcrumb'] = 'show';
                            hash['no-breadcrumb'] = '';
                            updateNavBar(element, hash, breadcrumbs);
                            addthis.update('share', 'url', url);
                            addthis.update('share', 'title', title);
                        }
                    }

                    $(window).scroll(function(){
                        var mobile_size = $("header").height() + $("#discussion_board_topbar").height() + $(".csMini").height() - ($("footer").height()/2);
                        var web_size = $(document).height() - $(window).height();
                        var current = $(window).scrollTop();
                        if(current + 1000 >= mobile_size || current + 600 >= web_size){
                            if($('.cxshowmorefeeditems')!=null && $('.cxshowmorefeeditems').length>0 && !feed_refresh_on){
                                feed_refresh_on = true;
                                chatterService.getFeed().showMoreFeedItems('click', Ext.select('.cxshowmorefeeditems').elements[0]);
                            }else{
                                //No more questions to load
                            }
                        }
                    });
                </script>

                <style>
                    /******* Override general styles from lunch *********/
                    body{
                        font-size: 12px;
                        line-height: 16px;
                    }

                    h1, h2, h3, h4, h5, h6 {
                        color: inherit;
                        font-weight: bold;
                        line-height: 0;
                    }

                    h4 {
                        font-size: 13px;
                    }
                    p {
                        margin: 0;
                    }


                    textarea, input[type="text"], input[type="password"], input[type="datetime"], input[type="datetime-local"], input[type="date"], input[type="month"], input[type="time"], input[type="week"], input[type="number"], input[type="email"], input[type="url"], input[type="search"], input[type="tel"], input[type="color"], .uneditable-input {
                        background-color: none;
                        border: none;
                        box-shadow: none;
                        transition: none;
                    }

                    select, textarea, input[type="text"], input[type="password"], input[type="datetime"], input[type="datetime-local"], input[type="date"], input[type="month"], input[type="time"], input[type="week"], input[type="number"], input[type="email"], input[type="url"], input[type="search"], input[type="tel"], input[type="color"], .uneditable-input {
                        border-radius: 0;
                        margin-bottom: 0;
                        padding: 0;
                    }

                    .label{
                        background-color: none;
                        border-radius: none;
                    }

                    .overlayDialog{
                        width: 480px !important;
                    }
                    #ChatterServiceDeleteConfirmationFocusPoint {
                        white-space: nowrap;
                    }

                    /**/

                    /*.scrn_mobile{
                        display: none;
                    }
                    .scrn_standard{
                        display: block;
                    }

                    .scrn_mobile_title{
                        widht: 200px;
                    }

                    .forums_fb_button {
                        margin-right: 0px;
                    }

                    .cxthefeed {
                        clear: none;
                    }*/

                    /*.forums_social_media_container:after{
                        clear: both;
                        content: ".";
                        display: block;
                        height: 0;
                        visibility: hidden;
                    }*/

                    .threecolumn:after{
                        clear: both;
                        content: ".";
                        display: block;
                        height: 0;
                        visibility: hidden;
                    }
                    .threecolumn .mainContent{
                        margin-left: 20px;
                    }
                    .threecolumn .lowerMainContent .centerContent {
                        padding-left: 0px;
                    }

                    .threecolumn .centerContent{
                        float: none;
                    }

                    #discussion_board_topbar{
                        background-color: #92d5f0;
                    }

                    /*.discussion_board_container{
                        width: 974px;
                        margin: 0 auto;
                    }
                    .discussion_board_container:after{
                        clear: both;
                        content: ".";
                        display: block;
                        height: 0;
                        visibility: hidden;
                    }*/

                    .cxquestionheader .feeditemtext.cxquestionbodypreview div{
                        height: 40px;
                    }

                    .feeditemcontent .read-more-link {
                        position: static;
                        display: block;
                        right: 9px;
                        bottom: 0;
                    }

                    @media (min-width: 950px) {
                        .feeditemcontent .read-more-link {
                            position: absolute;
                        }
                    }

                    @media (max-width: 1040px) {

                        .csMini .threecolumn {
                            width: 94%;
                        }

                        .csMini .threecolumn .mainContent{
                            float: none;
                            width: auto;
                            margin-left: 230px;
                        }

                        .csMini .mainContent .lowerMainContent {
                            width: 91%;
                        }

                        .threecolumn .centerContent {
                            width: 100%;
                        }
                    }

                    @media (max-width: 970px) {

                        .csMini .threecolumn {
                            width: 92%;
                        }

                    }

                    @media (max-width: 767px){

                        /*.discussion_board_container{
                            width: 100%;
                        }

                        .discussion_board_container{
                            width: 100%;
                        }*/

                        .csMini .threecolumn .mainContent{
                            margin-left: 0px;
                        }

                        #cs\:theFeed{
                            padding: 10px 0 0;
                            margin-top: 10px;
                        }

                        .csfeedcontainer {
                            padding-bottom: 0;
                        }

                        .csfeedcontainer .feeditem {
                            margin: 0 0 10px;
                        }

                        .csfeedcontainer .cxquestionheader .feeditemtext {
                            margin-right: 0px;
                        }

                        .cxPopularFeed .cxfeeditem .cxfeeditemcontent {
                            padding-left: 10px !important;
                            padding-right: 10px;
                        }

                        h4.cxquestiontitlewithlink{
                            margin-bottom: 0px;
                        }

                        .cxquestionheader .cxquestionbodypreview.feeditemtext {
                            margin-top: 0;
                        }
                    }


                    @media (max-width: 610px){

                        .threecolumn .leftContent {
                            width: 100%;
                        }

                        .csMini .threecolumn .mainContent {
                            clear: both;
                            float: none;
                            margin-left: 0px;
                            width: auto;
                        }
                    }

                    @media (min-width: 768px) and (max-width: 979px) {
                        /* here */
                        /*.discussion_board_container{
                            width: 750px;
                        }*/
                    }

                    /* Landscape phones and down */
                    /*@media (max-width: 448px) {
                        .scrn_mobile{
                            display: block;
                        }
                        .scrn_standard{
                            display: none;
                        }
                    }*/

                    .serviceCommunityDeflectionActions .actions .proceedtopost button.uiButton{
                        background: none repeat scroll 0 0 #31A3E0 !important;
                        border: 0 !important;
                        box-shadow: none !important;
                    }

                    .serviceCommunityDeflectionActions .actions .proceedtopost button.uiButton span{
                        background: transparent;
                    }

                    .serviceCommunityAskWidget .buttonbox button.cancelbutton{
                        background: #cccccc;
                        border: 0;
                        margin-right: 10px;
                    }

                    .serviceCommunityAskWidget .buttonbox button.postbutton.uiButton{
                        background: none repeat scroll 0 0 #31A3E0 !important;
                        border: 0 !important;
                        box-shadow: none !important;
                    }

                    .serviceCommunityAskWidget .buttonbox button.cancelbutton span, .serviceCommunityAskWidget .buttonbox button.postbutton.uiBlock span{
                        background: transparent;
                    }

                    .cafiltersupermenu{
                        float: left;
                    }

                    .cafiltersupermenu.zen .zen-options a:hover,
                    .cafiltersupermenu.zen .zen-options a:focus {
                        color: #048ec6;
                    }

                    .facet.facetheader.filterHeader h4,
                    .facet.facetheader.sortByHeader h4 {
                        color: #01344e;
                    }

                    .start_button{
                        float: right;
                        text-align: center;
                        line-height: 25px;
                        margin: 0 5px 0 0px !important;
                        padding: 7px 10px;
                        width: 200px !important;
                        -moz-box-sizing: border-box;
                        box-sizing: border-box;
                        background-image: linear-gradient(to bottom, #FFFFFF 0%, #EFEFEF 100%);
                        margin: 0px 5px 0px 5px;
                        width: 142px;
                        border: 1px solid #A7A7A7;
                        font-size: 18px;
                        color: #048ec6;
                        cursor: pointer;
                    }

                    .qtip-df{
                        background: #ffffff;
                        border: 1px solid rgb(0,168,220);
                        font-size: 14px;
                        line-height: 14px;
                    }

                    .moderation_controls{
                        float:right;
                    }

                    .moderation_arrow{
                        background: url(/img/chatterservice/btnArrow_sprite.png) no-repeat scroll right -55px transparent;
                        padding: 0 18px 0 0;
                    }

                    .moderation_dropdown{
                        display: none;
                        text-align: left;
                        position: absolute;
                        left: 0;
                        top: 19px;
                        border: 1px solid #b6b6b6;
                        margin: 0;
                        padding: 4px;
                        background-color: #fff;
                        -webkit-border-radius: 5px;
                        -moz-border-radius: 5px;
                        border-radius: 5px;
                        -webkit-box-shadow: 0 2px 5px #a0a6ab;
                        -moz-box-shadow: 0 2px 5px #a0a6ab;
                        box-shadow: 0 2px 5px #a0a6ab;
                    }

                    .moderation_dropdown li{
                        float: left;
                        clear: both;
                    }

                    .moderation_dropdown a{
                        height: 12px;
                        padding: 4px 9px;
                        text-align: left;
                        cursor: pointer;
                        line-height: 1em;
                        color: #222;
                        white-space: nowrap;
                        -webkit-border-radius: 9px;
                        -moz-border-radius: 9px;
                        border-radius: 9px;
                        font-size: 1.25em !important;
                    }

                    .moderation_dropdown a:hover{
                        background-color: #cfeef8;
                        color: #015ba7;
                        cursor: pointer;
                    }

                    .moderation_item{
                        position: relative;
                    }

                    #simplemodal-overlay{
                        background-color: #31A3E0 !important;
                    }

                    .categories_list{
                        margin-top: 10px;
                        padding: 0;
                        list-style: none;
                    }

                    .categories_list li{
                        margin: 0;
                        padding: 2px 0;
                    }

                    .categories_list a{
                        text-decoration: none;
                        color: #2a97d4;
                        font-weight: bold;
                        font-size: 11px;
                    }

                    .csfeedcontainer .feeditem{
                        z-index: 0;
                    }

                    .ui-widget-overlay{
                        background-color: #31A3E0;
                    }

                    .ui-dialog{
                        background-color: #fff;
                        border-color: #2a97d4;
                        border-radius: 10px;
                        padding: 35px;
                        box-shadow: 0px 0px 10px #888;
                    }

                    .modal-backdrop{
                        background: #aaaaaa;
                        opacity: 0.3;
                    }

                    .modal-header .close {
                        margin-top: 8px;
                        right: 0px;
                    }

                    #filterDisplay, #sortDisplay {
                        color: #048ec6;
                    }

                    .feeditemtext.cxquestionbodypreview,
                    .feedcommenttext,
                    div.feeditemtext.cxnotchatterlikesiv {
                        font-size: 14px;
                    }

                    .feeditemcontent.cxfeeditemcontent li.feeditemtimestamp {
                        font-size: 14 !important;
                    }
                </style>

                <style>
                    .feeditemtext div,
                    .feeditemtext span,
                    .feeditemtext p,
                    .feeditemtext a{
                        font-family: ProximaNovaRegular !important;
                        font-size: 15px !important;
                    }
                    .feeditemtext a,
                    .feeditemtext a *{
                        color: #048ec6 !important;
                    }
                    h4.feeditemtext a {
                        font-size: 1.3em !important;
                    }
                    .datacategorylinks .csChildOption a {
                        font-size: 15px;
                        font-weight: normal;
                    }
                    .cxquestionheader .feeditemtext.cxquestionbodypreview div {
                        height: auto;
                    }
                    .feeditemtext.cxquestionbodypreview {
                        height: auto;
                        max-height: 67px;
                    }
                    .csfeedcontainer .feeditemcontent {
                        padding-left: 15px;
                        padding-right: 15px;
                    }

                    #searchInput:focus{
                      box-shadow:  none;
                    }
                    
                    .searchbutton.uiButton--default.uiButton{
                       border: none;
                       box-shadow: none;
                    }
                    .searchbutton.uiButton--default.uiButton[readonly]{
                       cursor: not-allowed;
                    }
                    /* hiding the button until the issue with proceedToPost event gets fixed */
                    #discussion_button{
                      display: none;
                    }
                </style>
        
        <link href="/resource/stylesheets/profile.min.css" rel="stylesheet" type="text/css" />

    </head>

    <body>

        <img src="//res.cloudinary.com/hy4kyit2a/image/upload/sd_social300x300_1.png" style="display: none;" />

        <header><!--<dfc-header>-->
<!--<script type="text/javascript" src="/custom.js"></script>-->
    <div class="navbar navbar-static-top">
            <div class="navbar-inner">
                <div class="container">
                    <div class="mobileHeaderContainer">
                        <a class="brand clearfix" href="/"><img src="/resources2/images/salesforce-header-logo.png" class="sewg314"/></a>
                        <div class="headerButtonsContainer">
                            <div class="spanButton clearfix pull-right">
                                <a class="btn btn-success" type="button" href="/signup?d=70130000000td6N">
Sign Up &rsaquo;                                </a>
                            </div>
                            <div style="position: relative;" class="spanButton clearfix pull-right">
                                <BUTTON id="login-button" class="btn btn-primary" type="button">
Login &rsaquo;                              </BUTTON>
                                <div id="user-info-container" style="display: none;">
                                    <div id="user-info-content">
                                        <div id="user-info-header" class="clearfix">
                                            <div id="user-info-picture">
&nbsp;                                          </div>
                                            <div id="user-info-text-container">
                                                <div id="user-info-name">
&nbsp;                                              </div>
                                                <div id="user-info-username">
&nbsp;                                              </div>
                                                <div class="clearfix">
&nbsp;                                              </div>
                                            </div>
                                        </div>
                                        <div id="user-info-profile">
                                            <ul class="unstyled">
                                                <li id="MyDeveloperAcc">
                                                    <a>
My Developer Account >                                                  </a>
                                                </li>
                                                <li id="CreateNewAcc">
                                                    <a>
Create Account >                                                    </a>
                                                </li>
                                                <li id="MySettings">
                                                    <a>
My Settings >                                                   </a>
                                                </li>
                                            </ul>
                                        </div>
                                        <button id="user-info-logout" onclick="javascript:void(0);">
Log out                                     </button>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="social-search clearfix pull-right">
                            <div id="search-social-container" class="search-social-inner clearfix" data-placeholder="Search">
                                <gcse:searchbox-only resultsUrl="https://go.pardot.com/s/27572/bZmGraVP6uMckd2zJnklMehlfDezI7wZ" enableAutoComplete="true">
&nbsp;                              </gcse:searchbox-only>
                                <div id="login-logout2" class="login-logout hidden">
                                    <A id="sdn-login-link2" class="login-link" href="//org.developer.salesforce.com/forums/CommunitiesLogin?startURL=">
Login                                   </A>
                                    <ul class="nav nav-pills">
                                        <li class="dropdown">
                                            <a class="dropdown-toggle" data-toggle="dropdown" href="#link">
<img src="/resource/images/user-picture.jpg"/>                                          </a>
                                            <ul class="dropdown-menu">
                                                <li class="name">
                                                    <a href="#">
                                                        <span data-user-field="firstname">
&nbsp;                                                      </span>
                                                        <span data-user-field="lastname">
&nbsp;                                                      </span>
                                                    </a>
                                                </li>
                                                <li class="email" data-user-field="username">
&nbsp;                                              </li>
                                                <li class="divider">
&nbsp;                                              </li>
                                                <li class="logout">
                                                    <a href="#link">
Logout                                                  </a>
                                                </li>
                                            </ul>
                                        </li>
                                    </ul>
                                </div>
                            </div>
                        </div>
                        <div style="height: auto;" class="nav-collapse in collapse">
                            <ul id="nav-to-highlight-based-on-url2" class="nav primary-nav clearfix">
                                <li class="dropdown">
                                    <a data-toggle="dropdown" href="/platform/overview">
Products                                    </a>
                                    <ul class="dropdown-menu">
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/platform">
App Cloud                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/platform/force.com">
- Force.com                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/platform/heroku">
 - Heroku                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/lightning">
 - Lightning                                            </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/mobile">
 - Mobile                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com">
 - Trailhead                                            </a>
                                        </li>
                                                                                <li class="spaced-item">
                                            <a class="medium-link" href="/platform/dx">
 - Salesforce DX                                            </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/platform/appexchange">
 - AppExchange                                          </a>
                                        </li>
                                    </ul>
                                </li>
                                <li class="dropdown">
                                    <a data-toggle="dropdown" href="/resources">
Resources                                   </a>
                                    <ul class="dropdown-menu library">
                                        <li style="overflow:hidden;">
                                            <div style="width:265px;" class="pull-left span">
                                                <p>

    <em>Learn</em>
                                                </p>
                                                <ul style="width:50.0%;float:left;" class="unstyled">
                                                    <li class="spaced-item">
                                                        <A class="medium-link" href="/gettingstarted">
Getting Started                                                     </A>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/docs">
Documentation                                                       </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/blogs/developer-relations/2016/09/winter-17-highlights-developers.html">
Release Overview                                                        </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="https://trailhead.salesforce.com">
Trailhead                                                       </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Developer_Library">
Books &amp; Cheat Sheets                                                        </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/content/type/Webinar">
On-Demand Webinars                                                      </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="http://certification.salesforce.com/platform-developers" target="_blank">
Certification <i class="icon-external-link"></i>                                                        </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/blogs/">
Blogs                                                       </a>
                                                    </li>
                                                </ul>
                                            </div>
                                            <div style="width:244px;" class="pull-left span">
                                                <p>

    <em>Tools</em>
                                                </p>
                                                <ul style="width:50.0%;float:left;" class="unstyled">
                                                    <li class="spaced-item medium-link">
                                                        <a href="/page/Force.com_IDE">Force.com IDE</a>
                                                    </li>
                                                    <li class="spaced-item medium-link">
                                                        <a href="/tools/forcecli">Force.com CLI</a>
                                                    </li>
                                                    <li class="spaced-item medium-link">
                                                        <a href="https://www.lightningdesignsystem.com/" target="_blank">
Lightning Design System <i class="icon-external-link"></i>                                                      </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Security_Tools">
Source Code Scanner                                                     </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Tools">
More Tools &amp; Toolkits                                                       </a>
                                                    </li>
                                                </ul>
                                            </div>
                                            <div class="pull-left span">
                                                <p>

    <em>By Topic</em>
                                                </p>
                                                <ul style="width:50.0%;float:left;" class="unstyled">
                                                    <li class="spaced-item medium-link">
                                                        <a href="/page/App_Distribution">
App Distribution                                                        </a>
                                                    </li>
                                                    <li class="spaced-item medium-link">
                                                        <a href="/page/App_Logic">
App Logic                                                       </a>
                                                        <li class="spaced-item medium-link">
                                                            <a href="/page/Architect_Core_Resources">
Architect                                                           </a>
                                                        </li>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Database">
Database                                                        </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/devcenter/lightning">
Lightning                                                       </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/devcenter/mobile">
Mobile                                                      </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Integration">
Integration                                                     </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Security">
Security                                                        </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/UserInterface">
User Interface                                                      </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Websites">
Websites                                                        </a>
                                                    </li>
                                                </ul>
                                            </div>
                                        </li>
                                    </ul>
                                </li>
                                <li class="dropdown">
                                    <a data-toggle="dropdown" href="//events.developerforce.com/signup?d=70130000000tgM8">
Community                                   </a>
                                    <ul class="dropdown-menu">
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/forums">
Developer Forums                                            </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/calendar">
Events Calendar                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/mvp">
Developer MVPs                                          </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="http://www.meetup.com/pro/salesforcedevs" target="_blank">
Developer Groups <i class="icon-external-link"></i>                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/success-stories">
Developer Success Stories                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs/">
Blogs                                           </a>
                                        </li>
                                    </ul>
                                </li>
                                <li class="dropdown">
                                    <a data-toggle="dropdown" href="//events.developerforce.com/signup?d=70130000000tgM8">
Blog                                    </a>
                                    <ul class="dropdown-menu">
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs">
All Blogs                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs/developer-relations/">
Developer Relations                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs/engineering">
Engineering                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs/labs">
Force.com Labs                                          </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs/tech-pubs">
Tech Docs                                           </a>
                                        </li>
                                    </ul>
                                </li>
                                <li class="dropdown">
                                    <a data-toggle="dropdown" href="https://trailhead.salesforce.com">
Trailhead                                   </a>
                                    <ul class="dropdown-menu">
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com">
Trailhead                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com/trails">
 - Trails                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com/modules">
 - Modules                                          </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com/projects">
 - Projects                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com/super_badges">
 - Superbadges                                          </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com/trailblazers">
 - Trailblazers                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://developer.salesforce.com/forums?communityId=09aF00000004HMGIA2#!/feedtype=RECENT&amp;dc=Trailhead&amp;criteria=ALLQUESTIONS" target="_blank">
Get Help                                            </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://success.salesforce.com/_ui/core/chatter/groups/GroupProfilePage?g=0F9300000009Nek" target="_blank">
Join the Community <i class="icon-external-link"></i>                                           </a>
                                        </li>
                                    </ul>
                                </li>
                            </ul>
                        </div>
                    </div>
                    <div class="mobile mobileHeader">
                        <a id="mobileMenu">
<img src="/resource/images/MenuMobile.png"/>                        </a>
                        <a class="mobileLogo" href="/">
<img src="/resource/images/salesforce-developer-network-logo_1.png" class="sewg314" style="width:118px;"/>                      </a>
                        <a id="mobileSearch">
<img src="/resource/images/SearchMobile.png"/>                      </a>
                    </div>
                </div>
            </div>
        </div>
<script src="/resource/javascripts/afterheader.min.js"></script>

<script>
    function call_campaigns_cookie(){
        var params = document.location.search.substring(1);
        var utm_source = '';
        var utm_medium = '';
        var utm_campaign = '';
        var dr = '';
        params_array = params.split('&');
        for(i=0;i<params_array.length;i++){
            param_array = params_array[i].split('=');
            if(param_array[0]=='utm_source'){
                utm_source = param_array[1];
            }else if(param_array[0]=='utm_medium'){
                utm_medium = param_array[1];
            }else if(param_array[0]=='utm_campaign'){
                utm_campaign = param_array[1];
            }else if(param_array[0]=='dr'){
                dr = param_array[1];
            }
        }

        if(utm_source!=null && utm_source!='' && 
            utm_medium!=null && utm_medium!='' && 
            utm_campaign!=null && utm_campaign!=''){
            //do call
            $.get( "/events/campaigns_cookie", { utm_source: utm_source, utm_medium: utm_medium, utm_campaign: utm_campaign, dr: dr } );
        }
    }
    function animateSearchIn() {
        $('#mobileSearchContainerOverlay').fadeIn();
        $('#mobileSearchContainer').fadeIn();
        $('.gsc-input').focus();
        $("#mobileSearchContainer .searchBar").animate({
          top: '0px',
        }, 500, function() {
            
            $("#mobileSearchContainer .searchBar").animate({
              top: '-20px',
            }, 300);
            
        });
    }
    
    function animateSearchOut() {
        $("#mobileSearchContainer .searchBar").animate({
          top: '0px',
        }, 300, function() {
            $("#mobileSearchContainer .searchBar").animate({
              top: '-80px',
            }, 500, function() {
                $('#mobileSearchContainer').fadeOut();
                $('#mobileSearchContainerOverlay').fadeOut();
                $('.gsc-input').val('');
            });
        });
    }
    
    var intval_placeholder_search;
    
    function checkPlaceholderSearch(){
        if( jQuery("#newSearchContainer").find('input[name="search"]').length == 1 ){
            var a=jQuery("#newSearchContainer");
            a.find('input[name="search"]').attr("placeholder",a.attr("data-placeholder"));
            
            $('#newSearchContainer td.gsc-input').after($('<div class="clear-icon"></div>'));
        
            $('.clear-icon').click(function(){
                $('#newSearchContainer input.gsc-input').val('');
            });
            clearInterval(intval_placeholder_search);
        }
    }
    
    function makeNewSearch(){
      var newMobileSearchOverlay = $('<div></div>').attr('id', 'mobileSearchContainerOverlay');
      var newMobileSearch = $('<div></div>').attr('id', 'mobileSearchContainer');
      var searchBar = $('<div></div>').addClass('searchBar');
        
      var newSearchContainer = $('<div></div>').attr({
        id: 'newSearchContainer',
        'data-placeholder':'Search'
      });
        
      var newSearch = $('<gcse:searchbox-only></gcse:searchbox-only>').attr({
          resultsUrl : '//go.pardot.com/s/27572/bZmGraVP6uMckd2zJnklMehlfDezI7wZ',
          enableAutoComplete : true
      });
        
      $(newSearchContainer).append(newSearch);
      
      $(searchBar).append(newSearchContainer);
      $(newMobileSearch).append($(searchBar));
        
      $('body').prepend(newMobileSearchOverlay);
      $('body').prepend(newMobileSearch);
      
      $(newMobileSearchOverlay).click(function(){
          animateSearchOut();
      });
        
        
      if( jQuery("#newSearchContainer").find('input[name="search"]').length == 0 ){
          intval_placeholder_search = setInterval(function(){ checkPlaceholderSearch() }, 100);
      }
    }
    
    var intervalBtn;
    
    function placeMobileSearchCancelBtn(){
        if( $('#mobileSearchContainer td.gsc-clear-button').length > 0 ){
            
            clearInterval(intervalBtn);
            
            $('#mobileSearchContainer .gsc-search-button').remove();
        
            var cancelBtn = $('<button></button>');

            $(cancelBtn).text('Cancel').attr('type', 'button').click(function(){
                hideMobileSearchContainer();
            });
            
            
            
            $('#mobileSearchContainer div.gsc-clear-button').remove();
            $('#mobileSearchContainer td.gsc-clear-button').append(cancelBtn);
        }
    }

    function showMobileSearchContainer(){
        
        if( $('#mobileSearchContainer .gsc-clear-button button').length == 0 ){
            placeMobileSearchCancelBtn();
        }
        
        if( $('#mobileSearchContainer td.gsc-clear-button').length == 0 ){
            intervalBtn = setInterval(function(){placeMobileSearchCancelBtn()}, 500);
        }
        animateSearchIn();
        
    }
    
    function hideMobileSearchContainer(){
        animateSearchOut();
    }
    
    function mobileSidebarFix(){
        if( $('body').width() <= 979 ){
            $('.mobileHeaderContainer').addClass('on-mobile');
        }else{
            $('.mobileHeaderContainer').removeClass('on-mobile');
        }
    }
    
    var hideMobileHeaderContainer = true;


    $(document).ready(function(){
        
        /*!
        * jquery.scrollto.js 0.0.1 - https://github.com/yckart/jquery.scrollto.js
        * Scroll smooth to any element in your DOM.
        *
        * Copyright (c) 2012 Yannick Albert (http://yckart.com)
        * Licensed under the MIT license (http://www.opensource.org/licenses/mit-license.php).
        * 2013/02/17
        **/
        $.scrollTo = $.fn.scrollTo = function(x, y, options){
            if (!(this instanceof $)) return $.fn.scrollTo.apply($('html, body'), arguments);

            options = $.extend({}, {
                gap: {
                    x: 0,
                    y: 1
                },
                animation: {
                    easing: 'swing',
                    duration: 600,
                    complete: $.noop,
                    step: $.noop
                }
            }, options);

            return this.each(function(){
                var elem = $(this);
                elem.stop().animate({
                    scrollLeft: !isNaN(Number(x)) ? x : $(y).offset().left + options.gap.x,
                    scrollTop: !isNaN(Number(y)) ? y : $(y).offset().top + options.gap.y
                }, options.animation);
            });
        };
        
        makeNewSearch();
        mobileSidebarFix();
        
        $('#mobileSearch').unbind('click');
        
        $('#mobileSearch').click(function(){
          showMobileSearchContainer();
        });
        
        
        
        $(window).scroll(function() {
            
            if( hideMobileHeaderContainer == true && $(window).scrollLeft() > ($('.mobileHeaderContainer').outerWidth()/2) ){ 
                hideMobileHeaderContainer = false;
                
                setTimeout(function(){hideMobileHeaderContainer=true;}, 600);
                //$('html,body').scrollTo(0, 0, function(){});
                $('header').removeClass('showMobile');
                $('#SDNmaintemplate').removeClass('showMobile');
                $('footer').removeClass('showMobile');
            }
        });
        
        $(window).resize(function(){
            mobileSidebarFix();
        });
        call_campaigns_cookie();
    });
    
</script>

<link href='/resources2/stylesheets/dsc-header.css' rel='stylesheet' type='text/css'/>

<!--</dfc-header>-->
        </header><!--<dfc-nav>-->
<div id="navigation-bar">
  <div class="container">
      <div class="row">
          <div class="span9">
              <div>
          <div class="hidden <dfc-show-breadcrumb/>">
            <dfc-breadcumbs/>
          </div>
          <h1 class="<dfc-no-breadcrumb/>"><dfc-nav-title/></h1>
        </div>
          </div>
          <div class="span3">
              <div>
                  <div id="discussion_board_socialData">
                    <div id="forums_social_wrapper" class="forums_social_wrapper">
              <!-- Go to www.addthis.com/dashboard to customize your tools -->
                          <div class="addthis_custom_sharing"></div>
              <!-- AddThis Button END -->
              <div class="clear_both"></div>
            </div>
          </div>
        </div>
      </div>
      </div>
    </div>
</div>
<!--</dfc-nav>-->

            
            <div class="csMini">
                <div class="threecolumn">
                    <div class="leftContent">
                        <div><span id="j_id0:j_id1:j_id28">
    <div id="forums_login_wrapper"><span id="j_id0:j_id1:j_id28:j_id29:j_id43">
            <div class="forums_login_wrapper">
                <div class="reg-sign-up_div">
                    <div class="cloudImg"></div>
                    <div class="reg-sign-up_btn_div">
                        <button class="reg-sign-up" name="button" onclick="window.location.href='/forums/CommunitiesLogin?startURL=/forums'" type="submit">Login with Salesforce</button>
                    </div>
                </div>
                <div style="clear: both;"></div>
                <p class="dont_have_account">Don't have an account?</p>
                <a class="signup_dev_edition" href="/signup?d=70130000000tgM8">Signup for a Developer Edition</a>
            </div></span>
        <div style="clear:both"></div>
    </div></span>
                        </div>
                        <div class="caleftnavseparator"></div>
                        <div><span id="j_id0:j_id1:j_id47">
    
    <script>
  var categories_name = [];
   categories_name['Apex_Code_Development'] = 'Apex Code Development';
   categories_name['General_Development'] = 'General Development';
   categories_name['Visualforce_Development'] = 'Visualforce Development';
   categories_name['Formulas_Validation_Rules_Discussion'] = 'Formulas & Validation Rules Discussion';
   categories_name['APIs_and_Integration'] = 'APIs and Integration';
   categories_name['Jobs_Board'] = 'Jobs Board';
   categories_name['Other_Salesforce_Applications'] = 'Other Salesforce Applications';
   categories_name['Force_com_Sites_Site_com'] = 'Force.com Sites & Site.com';
   categories_name['Java_Development'] = 'Java Development';
   categories_name['Trailhead'] = 'Trailhead';
   categories_name['NET_Development'] = '.NET Development';
   categories_name['Perl_PHP_Python_Ruby_Development'] = 'Perl, PHP, Python & Ruby Development';
   categories_name['AppExchange_Directory_Packaging'] = 'AppExchange Directory & Packaging';
   categories_name['Mobile'] = 'Mobile';
   categories_name['Security'] = 'Security';
   categories_name['Lightning'] = 'Lightning';
   categories_name['Chatter_and_Chatter_API_Development'] = 'Chatter and Chatter API Development';
   categories_name['Visual_Workflow'] = 'Visual Workflow';
   categories_name['Salesforce_Labs_Open_Source_Projects'] = 'Salesforce Labs & Open Source Projects';
   categories_name['Desktop_Integration'] = 'Desktop Integration';
   categories_name['Apple_Mac_and_OS_X'] = 'Apple, Mac and OS X';
   categories_name['VB_and_Office_Development'] = 'VB and Office Development';
   categories_name['Schema_Development'] = 'Schema Development';
   categories_name['Architecture'] = 'Architecture';
   categories_name['General_JP'] = '一般 - General-JP';
   categories_name['App_Logic_JP'] = 'アプリケーションロジック - App Logic-JP';
   categories_name['User_Interface_JP'] = 'ユーザインタフェース - User Interface-JP';
   categories_name['Salesforce_Summer_of_Hacks'] = 'Salesforce Summer of Hacks';
   categories_name['Salesforce_1_Million_Hackathon'] = 'Salesforce $1 Million Hackathon';
   categories_name['Database_JP'] = 'データベース - Database-JP';
   categories_name['Integration_JP'] = 'インテグレーション - Integration-JP';
   categories_name['Web_Web_Sites_JP'] = 'Webサイト - Web Sites-JP';
   categories_name['App_Distribution_JP'] = 'アプリケーションの配布 - App Distribution-JP';
   categories_name['Mobile_JP'] = 'モバイル - Mobile-JP';
   categories_name['Announcements_JP'] = 'ご案内 - Announcements-JP';
   categories_name['Chatter_JP'] = 'ソーシャル - Chatter-JP';
   categories_name['Predictive_Services'] = 'Predictive Services';
 </script>
    
    <div class="datacategorylinks csoptimizequestion">
        <h3 id="ext-gen31" title="Filter questions and answers by topic">Browse by Topic</h3>
        <ul>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxApex_Code_Development" data-dc="Apex_Code_Development" href="/#!/feedtype=RECENT&amp;dc=Apex_Code_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Apex Code Development <span class="cacategorycounter">(56989)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxGeneral_Development" data-dc="General_Development" href="/#!/feedtype=RECENT&amp;dc=General_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />General Development <span class="cacategorycounter">(43016)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxVisualforce_Development" data-dc="Visualforce_Development" href="/#!/feedtype=RECENT&amp;dc=Visualforce_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Visualforce Development <span class="cacategorycounter">(29313)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxFormulas_Validation_Rules_Discussion" data-dc="Formulas_Validation_Rules_Discussion" href="/#!/feedtype=RECENT&amp;dc=Formulas_Validation_Rules_Discussion&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Formulas &amp; Validation Rules Discussion <span class="cacategorycounter">(7057)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxAPIs_and_Integration" data-dc="APIs_and_Integration" href="/#!/feedtype=RECENT&amp;dc=APIs_and_Integration&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />APIs and Integration <span class="cacategorycounter">(6845)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxJobs_Board" data-dc="Jobs_Board" href="/#!/feedtype=RECENT&amp;dc=Jobs_Board&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Jobs Board <span class="cacategorycounter">(6116)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxOther_Salesforce_Applications" data-dc="Other_Salesforce_Applications" href="/#!/feedtype=RECENT&amp;dc=Other_Salesforce_Applications&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Other Salesforce Applications <span class="cacategorycounter">(5632)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxForce_com_Sites_Site_com" data-dc="Force_com_Sites_Site_com" href="/#!/feedtype=RECENT&amp;dc=Force_com_Sites_Site_com&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Force.com Sites &amp; Site.com <span class="cacategorycounter">(3646)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxJava_Development" data-dc="Java_Development" href="/#!/feedtype=RECENT&amp;dc=Java_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Java Development <span class="cacategorycounter">(3523)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxTrailhead" data-dc="Trailhead" href="/#!/feedtype=RECENT&amp;dc=Trailhead&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Trailhead <span class="cacategorycounter">(3465)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxMobile" data-dc="Mobile" href="/#!/feedtype=RECENT&amp;dc=Mobile&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Mobile <span class="cacategorycounter">(1783)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxLightning" data-dc="Lightning" href="/#!/feedtype=RECENT&amp;dc=Lightning&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Lightning <span class="cacategorycounter">(1743)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxNET_Development" data-dc="NET_Development" href="/#!/feedtype=RECENT&amp;dc=NET_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />.NET Development <span class="cacategorycounter">(3338)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxPerl_PHP_Python_Ruby_Development" data-dc="Perl_PHP_Python_Ruby_Development" href="/#!/feedtype=RECENT&amp;dc=Perl_PHP_Python_Ruby_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Perl, PHP, Python &amp; Ruby Development <span class="cacategorycounter">(1899)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxAppExchange_Directory_Packaging" data-dc="AppExchange_Directory_Packaging" href="/#!/feedtype=RECENT&amp;dc=AppExchange_Directory_Packaging&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />AppExchange Directory &amp; Packaging <span class="cacategorycounter">(1820)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxMobile" data-dc="Mobile" href="/#!/feedtype=RECENT&amp;dc=Mobile&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Mobile <span class="cacategorycounter">(1783)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxSecurity" data-dc="Security" href="/#!/feedtype=RECENT&amp;dc=Security&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Security <span class="cacategorycounter">(1769)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxLightning" data-dc="Lightning" href="/#!/feedtype=RECENT&amp;dc=Lightning&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Lightning <span class="cacategorycounter">(1743)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxChatter_and_Chatter_API_Development" data-dc="Chatter_and_Chatter_API_Development" href="/#!/feedtype=RECENT&amp;dc=Chatter_and_Chatter_API_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Chatter and Chatter API Development <span class="cacategorycounter">(1446)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxVisual_Workflow" data-dc="Visual_Workflow" href="/#!/feedtype=RECENT&amp;dc=Visual_Workflow&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Visual Workflow <span class="cacategorycounter">(1125)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxSalesforce_Labs_Open_Source_Projects" data-dc="Salesforce_Labs_Open_Source_Projects" href="/#!/feedtype=RECENT&amp;dc=Salesforce_Labs_Open_Source_Projects&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Salesforce Labs &amp; Open Source Projects <span class="cacategorycounter">(1015)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxDesktop_Integration" data-dc="Desktop_Integration" href="/#!/feedtype=RECENT&amp;dc=Desktop_Integration&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Desktop Integration <span class="cacategorycounter">(975)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxApple_Mac_and_OS_X" data-dc="Apple_Mac_and_OS_X" href="/#!/feedtype=RECENT&amp;dc=Apple_Mac_and_OS_X&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Apple, Mac and OS X <span class="cacategorycounter">(712)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxVB_and_Office_Development" data-dc="VB_and_Office_Development" href="/#!/feedtype=RECENT&amp;dc=VB_and_Office_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />VB and Office Development <span class="cacategorycounter">(613)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxSchema_Development" data-dc="Schema_Development" href="/#!/feedtype=RECENT&amp;dc=Schema_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Schema Development <span class="cacategorycounter">(612)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxArchitecture" data-dc="Architecture" href="/#!/feedtype=RECENT&amp;dc=Architecture&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Architecture <span class="cacategorycounter">(443)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxSalesforce_Summer_of_Hacks" data-dc="Salesforce_Summer_of_Hacks" href="/#!/feedtype=RECENT&amp;dc=Salesforce_Summer_of_Hacks&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Salesforce Summer of Hacks <span class="cacategorycounter">(133)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxSalesforce_1_Million_Hackathon" data-dc="Salesforce_1_Million_Hackathon" href="/#!/feedtype=RECENT&amp;dc=Salesforce_1_Million_Hackathon&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Salesforce $1 Million Hackathon <span class="cacategorycounter">(129)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxPredictive_Services" data-dc="Predictive_Services" href="/#!/feedtype=RECENT&amp;dc=Predictive_Services&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Predictive Services <span class="cacategorycounter">(2)</span></a>
           </li>
        </ul>
        <ul>
            <li><a href="/forums/ForumsCategories" class="cacategoymorelink">View More Topics</a>
            </li>
            <li><a href="/forums/#!/feedtype=RECENT&criteria=ALLQUESTIONS" class="cacategoymorelink">See All Posts</a>
            </li>
        </ul>
    </div>
        <script>chatterService.initDatacategoryEvent();</script></span>
                        </div>
                        <div class="caleftnavseparator"></div>
                        
                    </div>
                    <div class="mainContent">
                        <div class="lowerMainContent" id="lowerMainContent">
                            <div class="centerContent" id="centerContent">
                                <div id="searchQuestion" style="display:none"><span id="j_id0:j_id1:j_id73"><script>if (!window.sfdcPage) {window.sfdcPage = new GenericSfdcPage();
UserContext.initialize({"ampm":["AM","PM"],"isAccessibleMode":false,"uiSkin":"Theme3","salesforceURL":"https://dfc-org-production.force.com?refURL=http%3A%2F%2Fdfc-org-production.force.com%2Fforums%2F","dateFormat":"M/d/yyyy","language":"en_US","locale":"en_US","userName":"salesforce_developer_community@dfc-org-production.force.com","userId":"005F0000003BGxZ","isCurrentlySysAdminSU":false,"renderMode":"RETRO","startOfWeek":"1","vfDomainPattern":"(?:[^.]+)*.na43.visual.force.com","auraDomain":"na43.lightning.force.com","dateTimeFormat":"M/d/yyyy h:mm a","orgPreferences":[{"index":257,"name":"TabOrganizer","value":true},{"index":113,"name":"GroupTasks","value":true}],"siteUrlPrefix":"/forums","isDefaultNetwork":false,"labelLastModified":"1479844900000","today":"11/26/2016 4:58 PM","timeFormat":"h:mm a","userPreferences":[{"index":112,"name":"HideInlineEditSplash","value":false},{"index":114,"name":"OverrideTaskSendNotification","value":false},{"index":115,"name":"DefaultTaskSendNotification","value":false},{"index":119,"name":"HideUserLayoutStdFieldInfo","value":false},{"index":116,"name":"HideRPPWarning","value":false},{"index":87,"name":"HideInlineSchedulingSplash","value":false},{"index":88,"name":"HideCRUCNotification","value":false},{"index":89,"name":"HideNewPLESplash","value":false},{"index":90,"name":"HideNewPLEWarnIE6","value":false},{"index":122,"name":"HideOverrideSharingMessage","value":false},{"index":91,"name":"HideProfileILEWarn","value":false},{"index":93,"name":"HideProfileElvVideo","value":false},{"index":97,"name":"ShowPicklistEditSplash","value":false},{"index":92,"name":"HideDataCategorySplash","value":false},{"index":128,"name":"ShowDealView","value":false},{"index":129,"name":"HideDealViewGuidedTour","value":false},{"index":132,"name":"HideKnowledgeFirstTimeSetupMsg","value":false},{"index":104,"name":"DefaultOffEntityPermsMsg","value":false},{"index":135,"name":"HideNewCsnSplash","value":false},{"index":101,"name":"HideBrowserWarning","value":false},{"index":139,"name":"HideDashboardBuilderGuidedTour","value":false},{"index":140,"name":"HideSchedulingGuidedTour","value":false},{"index":180,"name":"HideReportBuilderGuidedTour","value":false},{"index":183,"name":"HideAssociationQueueCallout","value":false},{"index":194,"name":"HideQTEBanner","value":false},{"index":193,"name":"HideChatterOnboardingSplash","value":false},{"index":195,"name":"HideSecondChatterOnboardingSplash","value":false},{"index":270,"name":"HideIDEGuidedTour","value":false},{"index":282,"name":"HideQueryToolGuidedTour","value":false},{"index":196,"name":"HideCSIGuidedTour","value":false},{"index":271,"name":"HideFewmetGuidedTour","value":false},{"index":272,"name":"HideEditorGuidedTour","value":false},{"index":205,"name":"HideApexTestGuidedTour","value":false},{"index":206,"name":"HideSetupProfileHeaderTour","value":false},{"index":207,"name":"HideSetupProfileObjectsAndTabsTour","value":false},{"index":213,"name":"DefaultOffArticleTypeEntityPermMsg","value":false},{"index":214,"name":"HideSelfInfluenceGetStarted","value":false},{"index":215,"name":"HideOtherInfluenceGetStarted","value":false},{"index":216,"name":"HideFeedToggleGuidedTour","value":false},{"index":268,"name":"ShowChatterTab178GuidedTour","value":false},{"index":275,"name":"HidePeopleTabDeprecationMsg","value":false},{"index":276,"name":"HideGroupTabDeprecationMsg","value":false},{"index":224,"name":"HideUnifiedSearchGuidedTour","value":false},{"index":226,"name":"ShowDevContextMenu","value":true},{"index":227,"name":"HideWhatRecommenderForActivityQueues","value":false},{"index":228,"name":"HideLiveAgentFirstTimeSetupMsg","value":false},{"index":232,"name":"HideGroupAllowsGuestsMsgOnMemberWidget","value":false},{"index":233,"name":"HideGroupAllowsGuestsMsg","value":false},{"index":234,"name":"HideWhatAreGuestsMsg","value":false},{"index":235,"name":"HideNowAllowGuestsMsg","value":false},{"index":236,"name":"HideSocialAccountsAndContactsGuidedTour","value":false},{"index":237,"name":"HideAnalyticsHomeGuidedTour","value":false},{"index":238,"name":"ShowQuickCreateGuidedTour","value":false},{"index":245,"name":"HideFilePageGuidedTour","value":false},{"index":250,"name":"HideForecastingGuidedTour","value":false},{"index":251,"name":"HideBucketFieldGuide","value":false},{"index":263,"name":"HideSmartSearchCallOut","value":false},{"index":265,"name":"HideSocialProfilesKloutSplashScreen","value":false},{"index":273,"name":"ShowForecastingQuotaAttainment","value":false},{"index":280,"name":"HideForecastingQuotaColumn","value":false},{"index":301,"name":"HideManyWhoGuidedTour","value":false},{"index":284,"name":"HideExternalSharingModelGuidedTour","value":false},{"index":298,"name":"HideFileSyncBannerMsg","value":false},{"index":299,"name":"HideTestConsoleGuidedTour","value":false},{"index":302,"name":"HideManyWhoInlineEditTip","value":false},{"index":303,"name":"HideSetupV2WelcomeMessage","value":false},{"index":312,"name":"ForecastingShowQuantity","value":false},{"index":313,"name":"HideDataImporterIntroMsg","value":false},{"index":314,"name":"HideEnvironmentHubLightbox","value":false},{"index":316,"name":"HideSetupV2GuidedTour","value":false},{"index":317,"name":"HideFileSyncMobileDownloadDialog","value":false},{"index":322,"name":"HideEnhancedProfileHelpBubble","value":false},{"index":328,"name":"ForecastingHideZeroRows","value":false},{"index":330,"name":"HideEmbeddedComponentsFeatureCallout","value":false},{"index":341,"name":"HideDedupeMatchResultCallout","value":false},{"index":340,"name":"HideS1BrowserUI","value":true},{"index":346,"name":"HideS1Banner","value":false},{"index":358,"name":"HideEmailVerificationAlert","value":false},{"index":354,"name":"HideLearningPathModal","value":false},{"index":359,"name":"HideAtMentionsHelpBubble","value":false},{"index":368,"name":"LightningExperiencePreferred","value":false}],"networkId":"0DBF0000000PAtV"});
}</script><script>chatterService.getToolbox().setIsGuestUser(true);</script><script>chatterService.getToolbox().setDataServletUrl('/forums/_ui/chatter/service/setup/ChatterServicePersonalSetup');</script><div id="auraElement-1"></div><div id="auraErrorMessage"></div>        <link href="/forums/l/%7B%22mode%22%3A%22PROD%22%2C%22app%22%3A%22serviceCommunity%3AserviceCommunityIntegrationApp%22%2C%22fwuid%22%3A%22TP0eb7RDpz6MQZsvYldHEg%22%2C%22loaded%22%3A%7B%22APPLICATION%40markup%3A%2F%2FserviceCommunity%3AserviceCommunityIntegrationApp%22%3A%22VpzVZrH5IXo-SFDgn6PEIA%22%7D%2C%22styleContext%22%3A%7B%22c%22%3A%22webkit%22%2C%22x%22%3A%5B%22isDesktop%22%5D%7D%2C%22ls%22%3A%22YN%22%7D/app.css" rel="stylesheet" type="text/css"/>
<style></style>       <script src="/forums/auraFW/resources/TP0eb7RDpz6MQZsvYldHEg/libs_GMT.js"></script>
       <script src="/forums/l/%7B%22mode%22%3A%22PROD%22%2C%22app%22%3A%22serviceCommunity%3AserviceCommunityIntegrationApp%22%2C%22fwuid%22%3A%22TP0eb7RDpz6MQZsvYldHEg%22%2C%22loaded%22%3A%7B%22APPLICATION%40markup%3A%2F%2FserviceCommunity%3AserviceCommunityIntegrationApp%22%3A%22VpzVZrH5IXo-SFDgn6PEIA%22%7D%2C%22ls%22%3A%22YN%22%7D/app.encryptionkey.js?jwt=45e60a6267582b79cf70c3ea3d0ecf86a32212780e7de0e14eff9b99aabe2aaf"></script>
       <script src="/forums/auraFW/javascript/TP0eb7RDpz6MQZsvYldHEg/aura_prod.js"></script>
       <script src="/forums/l/%7B%22mode%22%3A%22PROD%22%2C%22app%22%3A%22serviceCommunity%3AserviceCommunityIntegrationApp%22%2C%22fwuid%22%3A%22TP0eb7RDpz6MQZsvYldHEg%22%2C%22loaded%22%3A%7B%22APPLICATION%40markup%3A%2F%2FserviceCommunity%3AserviceCommunityIntegrationApp%22%3A%22VpzVZrH5IXo-SFDgn6PEIA%22%7D%2C%22ls%22%3A%22YN%22%7D/resources.js?version=1469064557000"></script>
       <script src="/forums/l/%7B%22mode%22%3A%22PROD%22%2C%22app%22%3A%22serviceCommunity%3AserviceCommunityIntegrationApp%22%2C%22fwuid%22%3A%22TP0eb7RDpz6MQZsvYldHEg%22%2C%22loaded%22%3A%7B%22APPLICATION%40markup%3A%2F%2FserviceCommunity%3AserviceCommunityIntegrationApp%22%3A%22VpzVZrH5IXo-SFDgn6PEIA%22%7D%2C%22ls%22%3A%22YN%22%7D/app.js"></script>
       <script src="/forums/l/%7B%22mode%22%3A%22PROD%22%2C%22app%22%3A%22serviceCommunity%3AserviceCommunityIntegrationApp%22%2C%22fwuid%22%3A%22TP0eb7RDpz6MQZsvYldHEg%22%2C%22loaded%22%3A%7B%22APPLICATION%40markup%3A%2F%2FserviceCommunity%3AserviceCommunityIntegrationApp%22%3A%22VpzVZrH5IXo-SFDgn6PEIA%22%7D%2C%22ls%22%3A%22YN%22%7D/bootstrap.js"></script>
<script>
    $A.initConfig({"instance":{"s":1,"v":{"componentDef":{"descriptor":"markup://serviceCommunity:serviceCommunityIntegrationApp"},"creationPath":"/*[0]"}},"ns":{"privileged":[],"internal":["FSC","FSCWavePU","FSCWave_preprod","FSCWave_uat","FSCWavepkg","FSC_CB","FSC_INS","FSC_RB","FSC_WM","FinServ","FinServWaveExt","FinServ_CB","FinServ_CB_Pre","FinServ_CB_SB","FinServ_INS","FinServ_INS_Pre","FinServ_INS_SB","FinServ_Pre","FinServ_RB","FinServ_RB_Pre","FinServ_RB_SB","FinServ_SB","FinServ_WM","FinServ_WM_Pre","FinServ_WM_SB","HC1","HC2","HC3","HC3a","HC4","HC4a","HC5","HealthCloud","HealthCloudGA","HealthCloudTest","HealthCloud_GA","HealthCloud_Pre","HealthCloud_SB","Health_Cloud_GA","adminui","aloha_sales_forecasting","aloha_sales_opptysplit","aloha_sales_tm2","analytics","analyticsHome","apex","appexUi","appexUiDev","assistantFramework","assistantFrameworkModules","aura","auraScl","auraStorage","auradev","auradocs","aurajstest","auraplat","builder_platform_process","calendar","clients","commerce","communitySetup","console","cooper","cordaDashboards","dashboards","dataImporter","ddcProspector","desktopDashboards","emailStream","emailui","embeddedService","environmenthub","et4ae5","externalServicesSetup","flexipage","flexipageEditor","flowruntime","force","forceChatter","forceCommunity","forceContent","forceKnowledge","forceLicensing","forceSearch","forceTopic","fsc1_r1","fsc2_r1","fsc3_r1","fscwealth","fscwealthE","fscwealthfuture","fscwealthpatch","fscwmmain","googleConnector","hammerSetup","hc1_r1","hc2_r1","hc3_r1","health_cloud","healthblitz","healthfuture","healthmain","healthone","healthpatch","healthtest","home","instrumentation","kbmanagement","knowledgeone","lcwizard","lightning","liveAgent","ltng","ltngdoc","ltngtools","ltngx","macros","mcdm","mcdm_1","mcdm_10","mcdm_2","mcdm_3","mcdm_4","mcdm_5","mcdm_6","mcdm_7","mcdm_8","mcdm_9","mobile","myday","native","notes","objectManager","offline","omni","onboarding","onboardingTest","one","onesetup","opencti","packagingSetupUI","platformencryption","processui","processuiappr","processuicommon","processuimgnt","processuirule","processuitest","reports","runtime_industries_survey","runtime_ladybug","runtime_platform_testhistory","runtime_platformservices_transactionSecurity","runtime_sales_activities","runtime_sales_campaign","runtime_sales_commerce","runtime_sales_forecasting","runtime_sales_lead","runtime_sales_merge","runtime_sales_pathassistant","runtime_sales_pipelineboard","runtime_sales_quotes","runtime_sales_skype","runtime_sales_social","runtime_sales_xclean","s1wizard","salesforceIdentity","securityHealth","securitycentral","selfService","serviceCommunity","setup","setupAssistant","setup_lightning_visualforce","setup_platform_cloudconsole","setup_platformservices_customplatform","setup_sales_leadiq","setup_sales_pathassistant","setup_service","setupnav","setupwizard","sfa","siteforce","siteforceBuilder","socialService","support","templatesetup","today","ui","uiExamples","uns","userProvisioningUI","visualEditor","voice","wave","wealthone","wealthoneblitz","wealthonep","wits","work","workAloha"]},"host":"/forums","context":{"mode":"PROD","app":"serviceCommunity:serviceCommunityIntegrationApp","contextPath":"/forums","fwuid":"TP0eb7RDpz6MQZsvYldHEg","loaded":{"APPLICATION@markup://serviceCommunity:serviceCommunityIntegrationApp":"VpzVZrH5IXo-SFDgn6PEIA"},"globalValueProviders":[{"type":"$SObjectType","values":{"CurrentUser":{"isChatterEnabled":false}}},{"type":"$Mail","values":{"areAssociationPermsEnabled":true,"isSaveAttachmentEnabled":true,"isCustomizable":false,"killerUX":true}},{"type":"$Locale","values":{"userLocaleLang":"en","userLocaleCountry":"US","language":"en","country":"US","variant":"","langLocale":"en_US","nameOfMonths":[{"fullName":"January","shortName":"Jan"},{"fullName":"February","shortName":"Feb"},{"fullName":"March","shortName":"Mar"},{"fullName":"April","shortName":"Apr"},{"fullName":"May","shortName":"May"},{"fullName":"June","shortName":"Jun"},{"fullName":"July","shortName":"Jul"},{"fullName":"August","shortName":"Aug"},{"fullName":"September","shortName":"Sep"},{"fullName":"October","shortName":"Oct"},{"fullName":"November","shortName":"Nov"},{"fullName":"December","shortName":"Dec"},{"fullName":"","shortName":""}],"nameOfWeekdays":[{"fullName":"Sunday","shortName":"SUN"},{"fullName":"Monday","shortName":"MON"},{"fullName":"Tuesday","shortName":"TUE"},{"fullName":"Wednesday","shortName":"WED"},{"fullName":"Thursday","shortName":"THU"},{"fullName":"Friday","shortName":"FRI"},{"fullName":"Saturday","shortName":"SAT"}],"labelForToday":"Today","firstDayOfWeek":1,"dateFormat":"MMM d, yyyy","datetimeFormat":"MMM d, yyyy h:mm:ss a","timeFormat":"h:mm:ss a","timezone":"GMT","timezoneFileName":"GMT","isEasternNameStyle":false,"numberFormat":"#,##0.###","decimal":".","grouping":",","zero":"0","percentFormat":"#,##0%","currencyFormat":"¤#,##0.00","currencyCode":"USD","currency":"$"}},{"type":"$Browser","values":{"containerVersion":"","isWEBKIT":true,"isIE11":false,"formFactor":"DESKTOP","isIE10":false,"isContainer":false,"isBlackBerry":false,"isIE7":false,"isIE6":false,"isIE9":false,"isIE8":false,"isDesktop":true,"isTablet":false,"isIPad":false,"isWindowsTablet":false,"isPhone":false,"S1Features":{"useNativeScroller":false,"isAsyncSaveEnabled":false,"isEncryptedStorageEnabled":true,"isSFXUrlFormatSupported":false,"isAuraParallelBootstrapLoadEnabled":true,"isSocialInsightsLogoAdmin":false,"isSFXInlineEditListViewEnabled":true,"areOfflineDraftsEnabled":false,"isEclairAdvancedFeaturesEnabled":false,"isAccountSuggestionsEnabled":false,"isAccountLogoEnabled":false,"isUitrkLoggingEnabled":true,"isTodayPreviewEnabled":false,"isOfflineEnabled":true},"isFIREFOX":false,"isWindowsPhone":false,"isOSX":false,"isAndroid":false,"isIPhone":false,"isIOS":false}},{"type":"$SfdcSite","values":{"pathPrefix":"/forums"}},{"type":"$Global","values":{"isVoiceOver":{"writable":true,"defaultValue":false},"appContextId":{"writable":true,"defaultValue":""},"dynamicTypeSize":{"writable":true,"defaultValue":""}}}],"enableAccessChecks":true}}, true, true, true);
    </script><script>$A.__aisScopedCallback(function() { $A.clientService.injectComponentAsync({'componentDef': 'markup://serviceCommunity:searchAskWidgetMain', 'attributes': { 'values' : {"searchAskState":0,"zoneId":"09aF00000004HMGIA2","guestUser":true,"noSignIn":true} }, 'localId': '1'}, 'auraElement-1', undefined); });</script><div id="cs:supportBubble" class="prompt" style="display:none;">
    <h3>Welcome to Support!</h3>
    <p>Search for an answer or ask a question of the zone or Customer Support.</p>
    <a href="javascript:openPopupFocusEscapePounds(%27https://dfc-org-production.force.com/forums/ChatterAnswersHelp%27, %27Help%27, 1024, 768, %27width=1024,height=768,resizable=yes,toolbar=yes,status=yes,scrollbars=yes,menubar=yes,directories=no,location=yes,dependant=no%27, false, false);" class="faqLink">Need help?</a>
    <a href="javascript:void(0);" onclick="chatterService.hideHelpWidget();" class="dismiss">Dismiss</a>
    <span class="csTip" title=""></span>
</div>
<script>Ext.fly(window).on('load', function() {if ((window.sfdcPage) && (sfdcPage.executeOnloadQueue)){sfdcPage.executeOnloadQueue();};chatterService.initSearchAsk({isTBEnabled:true,isRTEnabled:true,inPortal:false,isNewAuraPublisher:true,communityId:'09aF00000004HMGIA2',loginPageUrl:'https://dfc-org-production.force.com/forums/ChatterAnswersLogin'});});chatterService.getToolbox().setNoSignIn('true');chatterService.getToolbox().setLanguage('en_US');</script></span>
                                </div>
                                <div class="hidden" id="login_prompt_search">
                                    <p>You need to sign in to do that</p>
                                    <p><a href="/forums/CommunitiesLogin?startURL=/forums">Sign in to start searching questions</a></p>
                                    <br />
                                    <p>Don't have an account?</p>
                                    <p><a href="/signup?d=70130000000tgM8">Signup for a Developer Edition</a></p>
                                </div>
                                <div><span id="j_id0:j_id1:j_id77"><script>if (!window.sfdcPage) {window.sfdcPage = new GenericSfdcPage();
UserContext.initialize({"ampm":["AM","PM"],"isAccessibleMode":false,"uiSkin":"Theme3","salesforceURL":"https://dfc-org-production.force.com?refURL=http%3A%2F%2Fdfc-org-production.force.com%2Fforums%2F","dateFormat":"M/d/yyyy","language":"en_US","locale":"en_US","userName":"salesforce_developer_community@dfc-org-production.force.com","userId":"005F0000003BGxZ","isCurrentlySysAdminSU":false,"renderMode":"RETRO","startOfWeek":"1","vfDomainPattern":"(?:[^.]+)*.na43.visual.force.com","auraDomain":"na43.lightning.force.com","dateTimeFormat":"M/d/yyyy h:mm a","orgPreferences":[{"index":257,"name":"TabOrganizer","value":true},{"index":113,"name":"GroupTasks","value":true}],"siteUrlPrefix":"/forums","isDefaultNetwork":false,"labelLastModified":"1479844900000","today":"11/26/2016 4:58 PM","timeFormat":"h:mm a","userPreferences":[{"index":112,"name":"HideInlineEditSplash","value":false},{"index":114,"name":"OverrideTaskSendNotification","value":false},{"index":115,"name":"DefaultTaskSendNotification","value":false},{"index":119,"name":"HideUserLayoutStdFieldInfo","value":false},{"index":116,"name":"HideRPPWarning","value":false},{"index":87,"name":"HideInlineSchedulingSplash","value":false},{"index":88,"name":"HideCRUCNotification","value":false},{"index":89,"name":"HideNewPLESplash","value":false},{"index":90,"name":"HideNewPLEWarnIE6","value":false},{"index":122,"name":"HideOverrideSharingMessage","value":false},{"index":91,"name":"HideProfileILEWarn","value":false},{"index":93,"name":"HideProfileElvVideo","value":false},{"index":97,"name":"ShowPicklistEditSplash","value":false},{"index":92,"name":"HideDataCategorySplash","value":false},{"index":128,"name":"ShowDealView","value":false},{"index":129,"name":"HideDealViewGuidedTour","value":false},{"index":132,"name":"HideKnowledgeFirstTimeSetupMsg","value":false},{"index":104,"name":"DefaultOffEntityPermsMsg","value":false},{"index":135,"name":"HideNewCsnSplash","value":false},{"index":101,"name":"HideBrowserWarning","value":false},{"index":139,"name":"HideDashboardBuilderGuidedTour","value":false},{"index":140,"name":"HideSchedulingGuidedTour","value":false},{"index":180,"name":"HideReportBuilderGuidedTour","value":false},{"index":183,"name":"HideAssociationQueueCallout","value":false},{"index":194,"name":"HideQTEBanner","value":false},{"index":193,"name":"HideChatterOnboardingSplash","value":false},{"index":195,"name":"HideSecondChatterOnboardingSplash","value":false},{"index":270,"name":"HideIDEGuidedTour","value":false},{"index":282,"name":"HideQueryToolGuidedTour","value":false},{"index":196,"name":"HideCSIGuidedTour","value":false},{"index":271,"name":"HideFewmetGuidedTour","value":false},{"index":272,"name":"HideEditorGuidedTour","value":false},{"index":205,"name":"HideApexTestGuidedTour","value":false},{"index":206,"name":"HideSetupProfileHeaderTour","value":false},{"index":207,"name":"HideSetupProfileObjectsAndTabsTour","value":false},{"index":213,"name":"DefaultOffArticleTypeEntityPermMsg","value":false},{"index":214,"name":"HideSelfInfluenceGetStarted","value":false},{"index":215,"name":"HideOtherInfluenceGetStarted","value":false},{"index":216,"name":"HideFeedToggleGuidedTour","value":false},{"index":268,"name":"ShowChatterTab178GuidedTour","value":false},{"index":275,"name":"HidePeopleTabDeprecationMsg","value":false},{"index":276,"name":"HideGroupTabDeprecationMsg","value":false},{"index":224,"name":"HideUnifiedSearchGuidedTour","value":false},{"index":226,"name":"ShowDevContextMenu","value":true},{"index":227,"name":"HideWhatRecommenderForActivityQueues","value":false},{"index":228,"name":"HideLiveAgentFirstTimeSetupMsg","value":false},{"index":232,"name":"HideGroupAllowsGuestsMsgOnMemberWidget","value":false},{"index":233,"name":"HideGroupAllowsGuestsMsg","value":false},{"index":234,"name":"HideWhatAreGuestsMsg","value":false},{"index":235,"name":"HideNowAllowGuestsMsg","value":false},{"index":236,"name":"HideSocialAccountsAndContactsGuidedTour","value":false},{"index":237,"name":"HideAnalyticsHomeGuidedTour","value":false},{"index":238,"name":"ShowQuickCreateGuidedTour","value":false},{"index":245,"name":"HideFilePageGuidedTour","value":false},{"index":250,"name":"HideForecastingGuidedTour","value":false},{"index":251,"name":"HideBucketFieldGuide","value":false},{"index":263,"name":"HideSmartSearchCallOut","value":false},{"index":265,"name":"HideSocialProfilesKloutSplashScreen","value":false},{"index":273,"name":"ShowForecastingQuotaAttainment","value":false},{"index":280,"name":"HideForecastingQuotaColumn","value":false},{"index":301,"name":"HideManyWhoGuidedTour","value":false},{"index":284,"name":"HideExternalSharingModelGuidedTour","value":false},{"index":298,"name":"HideFileSyncBannerMsg","value":false},{"index":299,"name":"HideTestConsoleGuidedTour","value":false},{"index":302,"name":"HideManyWhoInlineEditTip","value":false},{"index":303,"name":"HideSetupV2WelcomeMessage","value":false},{"index":312,"name":"ForecastingShowQuantity","value":false},{"index":313,"name":"HideDataImporterIntroMsg","value":false},{"index":314,"name":"HideEnvironmentHubLightbox","value":false},{"index":316,"name":"HideSetupV2GuidedTour","value":false},{"index":317,"name":"HideFileSyncMobileDownloadDialog","value":false},{"index":322,"name":"HideEnhancedProfileHelpBubble","value":false},{"index":328,"name":"ForecastingHideZeroRows","value":false},{"index":330,"name":"HideEmbeddedComponentsFeatureCallout","value":false},{"index":341,"name":"HideDedupeMatchResultCallout","value":false},{"index":340,"name":"HideS1BrowserUI","value":true},{"index":346,"name":"HideS1Banner","value":false},{"index":358,"name":"HideEmailVerificationAlert","value":false},{"index":354,"name":"HideLearningPathModal","value":false},{"index":359,"name":"HideAtMentionsHelpBubble","value":false},{"index":368,"name":"LightningExperiencePreferred","value":false}],"networkId":"0DBF0000000PAtV"});
}</script><script>chatterService.getToolbox().setIsGuestUser(true);</script><script>chatterService.getToolbox().setDataServletUrl('/forums/_ui/chatter/service/setup/ChatterServicePersonalSetup');</script><div class="feedfiltersupermenu cafiltersupermenu zen"><div class="zen-select " data-sfdc-widget="SfdcCmp.Ui.Dropdown" role="application" 

        data-expandMode="click"

        data-autoFocus="true"
        
        data-autocollapse="true"
>


      <a id="feedFilterDropDownElement" class="zen-trigger " onclick="" href="javascript:void(0);" title="" aria-haspopup="true">
<span id="filterByTriggerText">Show</span><span id="filterDisplay" title="Show all questions in the zone as well as articles, if articles are enabled for your organization.">All Questions</span><span id="sortByTriggerText">sorted by</span><span id="sortDisplay" title="Show questions in order of the date they were asked.">Date Posted</span><span class="zen-selectArrow"></span>      </a>
        <div class="zen-options " role="menu" aria-labelledby="feedFilterDropDownElement">
<span class="facet facetheader filterHeader"><h4>Show</h4></span><span class="zen-optgroup combomenu-filter" data-sfdc-widget="SfdcCmp.Ui.OptGroup" role="radiogroup"><ul class="feedfilters"><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="#" class="cxcriteria cxALLQUESTIONS" data-criteria="ALLQUESTIONS" role="menuitemradio" title="Show all questions in the zone as well as articles, if articles are enabled for your organization.">All Questions</a></li><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="#" class="cxcriteria cxUNANSWERED" data-criteria="UNANSWERED" role="menuitemradio" title="Show all questions that don&#39;t have replies.">Unanswered Questions</a></li><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="#" class="cxcriteria cxOPENQUESTIONS" data-criteria="OPENQUESTIONS" role="menuitemradio" title="Show all questions that don&#39;t have a best answer.">Unsolved Questions</a></li><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="#" class="cxcriteria cxBESTANSWERS" data-criteria="BESTANSWERS" role="menuitemradio" title="Show all questions that have a best answer as well as articles, if articles are enabled for your organization.">Solved Questions</a></li></ul>
</span><span class="facet facetheader sortByHeader"><h4>sorted by</h4></span><span class="zen-optgroup combomenu-filter" data-sfdc-widget="SfdcCmp.Ui.OptGroup" role="radiogroup"><ul class="feedsortby"><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="?feedtype=RECENT" class="cxfeedtype cxRECENT" data-feedtype="RECENT" role="menuitemradio" title="Show questions in order of the date they were asked.">Date Posted</a></li><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="?feedtype=RECENT_REPLY" class="cxfeedtype cxRECENT_REPLY" data-feedtype="RECENT_REPLY" role="menuitemradio" title="Show questions that are new or have new comments first.">Recent Activity</a></li><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="?feedtype=POPULAR" class="cxfeedtype cxPOPULAR" data-feedtype="POPULAR" role="menuitemradio" title="Show questions with the highest number of upvotes, followers, and likes first.">Most Popular</a></li></ul>
</span>     </div>
</div>
</div><script>Sfdc.onReady(function(){chatterService.initFeedFilterEvent();});</script></span>
                                </div>
                                    <div class="user_stats start_button" id="discussion_button">+ Start a Discussion</div>
                                    <div class="hidden" id="login_prompt_button">
                                        <p>You need to sign in to do that</p>
                                        <p><a href="/forums/CommunitiesLogin?startURL=/forums">Sign in to start a discussion</a></p>
                                        <br />
                                        <p>Don't have an account?</p>
                                        <p><a href="/signup?d=70130000000tgM8">Signup for a Developer Edition</a></p>
                                    </div>
                                <div style="clear: both"></div><div id="j_id0:j_id1:communityFeed"><span id="j_id0:j_id1:j_id86"><script>if (!window.sfdcPage) {window.sfdcPage = new GenericSfdcPage();
UserContext.initialize({"ampm":["AM","PM"],"isAccessibleMode":false,"uiSkin":"Theme3","salesforceURL":"https://dfc-org-production.force.com?refURL=http%3A%2F%2Fdfc-org-production.force.com%2Fforums%2F","dateFormat":"M/d/yyyy","language":"en_US","locale":"en_US","userName":"salesforce_developer_community@dfc-org-production.force.com","userId":"005F0000003BGxZ","isCurrentlySysAdminSU":false,"renderMode":"RETRO","startOfWeek":"1","vfDomainPattern":"(?:[^.]+)*.na43.visual.force.com","auraDomain":"na43.lightning.force.com","dateTimeFormat":"M/d/yyyy h:mm a","orgPreferences":[{"index":257,"name":"TabOrganizer","value":true},{"index":113,"name":"GroupTasks","value":true}],"siteUrlPrefix":"/forums","isDefaultNetwork":false,"labelLastModified":"1479844900000","today":"11/26/2016 4:58 PM","timeFormat":"h:mm a","userPreferences":[{"index":112,"name":"HideInlineEditSplash","value":false},{"index":114,"name":"OverrideTaskSendNotification","value":false},{"index":115,"name":"DefaultTaskSendNotification","value":false},{"index":119,"name":"HideUserLayoutStdFieldInfo","value":false},{"index":116,"name":"HideRPPWarning","value":false},{"index":87,"name":"HideInlineSchedulingSplash","value":false},{"index":88,"name":"HideCRUCNotification","value":false},{"index":89,"name":"HideNewPLESplash","value":false},{"index":90,"name":"HideNewPLEWarnIE6","value":false},{"index":122,"name":"HideOverrideSharingMessage","value":false},{"index":91,"name":"HideProfileILEWarn","value":false},{"index":93,"name":"HideProfileElvVideo","value":false},{"index":97,"name":"ShowPicklistEditSplash","value":false},{"index":92,"name":"HideDataCategorySplash","value":false},{"index":128,"name":"ShowDealView","value":false},{"index":129,"name":"HideDealViewGuidedTour","value":false},{"index":132,"name":"HideKnowledgeFirstTimeSetupMsg","value":false},{"index":104,"name":"DefaultOffEntityPermsMsg","value":false},{"index":135,"name":"HideNewCsnSplash","value":false},{"index":101,"name":"HideBrowserWarning","value":false},{"index":139,"name":"HideDashboardBuilderGuidedTour","value":false},{"index":140,"name":"HideSchedulingGuidedTour","value":false},{"index":180,"name":"HideReportBuilderGuidedTour","value":false},{"index":183,"name":"HideAssociationQueueCallout","value":false},{"index":194,"name":"HideQTEBanner","value":false},{"index":193,"name":"HideChatterOnboardingSplash","value":false},{"index":195,"name":"HideSecondChatterOnboardingSplash","value":false},{"index":270,"name":"HideIDEGuidedTour","value":false},{"index":282,"name":"HideQueryToolGuidedTour","value":false},{"index":196,"name":"HideCSIGuidedTour","value":false},{"index":271,"name":"HideFewmetGuidedTour","value":false},{"index":272,"name":"HideEditorGuidedTour","value":false},{"index":205,"name":"HideApexTestGuidedTour","value":false},{"index":206,"name":"HideSetupProfileHeaderTour","value":false},{"index":207,"name":"HideSetupProfileObjectsAndTabsTour","value":false},{"index":213,"name":"DefaultOffArticleTypeEntityPermMsg","value":false},{"index":214,"name":"HideSelfInfluenceGetStarted","value":false},{"index":215,"name":"HideOtherInfluenceGetStarted","value":false},{"index":216,"name":"HideFeedToggleGuidedTour","value":false},{"index":268,"name":"ShowChatterTab178GuidedTour","value":false},{"index":275,"name":"HidePeopleTabDeprecationMsg","value":false},{"index":276,"name":"HideGroupTabDeprecationMsg","value":false},{"index":224,"name":"HideUnifiedSearchGuidedTour","value":false},{"index":226,"name":"ShowDevContextMenu","value":true},{"index":227,"name":"HideWhatRecommenderForActivityQueues","value":false},{"index":228,"name":"HideLiveAgentFirstTimeSetupMsg","value":false},{"index":232,"name":"HideGroupAllowsGuestsMsgOnMemberWidget","value":false},{"index":233,"name":"HideGroupAllowsGuestsMsg","value":false},{"index":234,"name":"HideWhatAreGuestsMsg","value":false},{"index":235,"name":"HideNowAllowGuestsMsg","value":false},{"index":236,"name":"HideSocialAccountsAndContactsGuidedTour","value":false},{"index":237,"name":"HideAnalyticsHomeGuidedTour","value":false},{"index":238,"name":"ShowQuickCreateGuidedTour","value":false},{"index":245,"name":"HideFilePageGuidedTour","value":false},{"index":250,"name":"HideForecastingGuidedTour","value":false},{"index":251,"name":"HideBucketFieldGuide","value":false},{"index":263,"name":"HideSmartSearchCallOut","value":false},{"index":265,"name":"HideSocialProfilesKloutSplashScreen","value":false},{"index":273,"name":"ShowForecastingQuotaAttainment","value":false},{"index":280,"name":"HideForecastingQuotaColumn","value":false},{"index":301,"name":"HideManyWhoGuidedTour","value":false},{"index":284,"name":"HideExternalSharingModelGuidedTour","value":false},{"index":298,"name":"HideFileSyncBannerMsg","value":false},{"index":299,"name":"HideTestConsoleGuidedTour","value":false},{"index":302,"name":"HideManyWhoInlineEditTip","value":false},{"index":303,"name":"HideSetupV2WelcomeMessage","value":false},{"index":312,"name":"ForecastingShowQuantity","value":false},{"index":313,"name":"HideDataImporterIntroMsg","value":false},{"index":314,"name":"HideEnvironmentHubLightbox","value":false},{"index":316,"name":"HideSetupV2GuidedTour","value":false},{"index":317,"name":"HideFileSyncMobileDownloadDialog","value":false},{"index":322,"name":"HideEnhancedProfileHelpBubble","value":false},{"index":328,"name":"ForecastingHideZeroRows","value":false},{"index":330,"name":"HideEmbeddedComponentsFeatureCallout","value":false},{"index":341,"name":"HideDedupeMatchResultCallout","value":false},{"index":340,"name":"HideS1BrowserUI","value":true},{"index":346,"name":"HideS1Banner","value":false},{"index":358,"name":"HideEmailVerificationAlert","value":false},{"index":354,"name":"HideLearningPathModal","value":false},{"index":359,"name":"HideAtMentionsHelpBubble","value":false},{"index":368,"name":"LightningExperiencePreferred","value":false}],"networkId":"0DBF0000000PAtV"});
}</script><script>chatterService.getToolbox().setIsGuestUser(true);</script><script>chatterService.getToolbox().setDataServletUrl('/forums/_ui/chatter/service/setup/ChatterServicePersonalSetup');</script><div class=" csoptimizequestion cxthefeed" id="cs:theFeed"><div><div class="cxfeedcontainer"><div class="csfeedcontainer cxSingleQuestionDetailFeed"><ul class="cxBreadcrumbs breadCrumbs"><li class="first cxBreadcrumbCriteria"><a href="#" class="cxquestionbreadcrumbbest"><span class="cxquestionbreadcrumbbest">Solved Questions</span></a></li><li class="last current"><span>This Question</span></li></ul>
<div class="cx906F00000008pc4 cxfeeditem feeditem" data-scc="{feedItemId:'906F00000008pc4IAA',ownerId:'005F0000003FfZc',communityId:'09aF00000004HMGIA2'}"><div class="feeditemcontent cxfeeditemcontent"><div class="cxquestionheader"><span class="usericon"><img src="https://dfc-org-production.force.com/img/userprofile/default_profile_45_v2.png" alt="RedSales" width="45" height="45" class="cxuserimage" title="RedSales" /></span><span class="feeditemfirstentity"><a href="https://dfc-org-production.force.com/forums/ForumsProfile?communityId=09aF00000004HMG&amp;userId=005F0000003FfZc&amp;showHeader=false">RedSales</a></span>&nbsp;<h1 class="feeditemtext feeditemheader cxnotchatterlikesiv">What does the &quot;%2F&quot; characters mean when used before an object in a URL?</h1><div class="feeditemtext cxnotchatterlikesiv"><p>Hello,</p><p> </p><p>I&#39;ve noted in Salesforce.com url&#39;s that querystring parameters often contain the characters %2F  before an object. What is the purpose of these characters &amp; what do they mean?</p><p> </p><p>An example is the following &quot;retURL=%2F01QQ1000007E4cm&quot;</p><p>Where &quot;01QQ1000007E4cm&quot; is the object id.</p><p> </p><p>Thanking you for your help.</p></div></div><ul class="feeditemfooter"><li class="feeditemtimestamp">May 10, 2011</li><li class="feeditemseparatingdot"> · </li><li class="cxlike" title="Like this"><a href="#" class="cxusefullink">Like</a></li><li class="upVoteCount" data-value="1">1</li><li class="feeditemseparatingdot"> · </li><li class="cxfollow" title="Follow this question to receive email updates"><a href="#" class="cxfollowlink">Follow</a></li><li class="followCount" data-value="0" title="0">0</li></ul>
<div class="feeditemextras"><div class="cxfeedcommentarrow feedcommentarrow"></div><div class="cxcomments feeditemcomments"><div class="cxbestReply"><div class="cx907F00000008sS3 feeditemcomment cxfeedcomment cxfeedItemBestReplyText" data-scc="{feedItemId:'907F00000008sS3IAI',ownerId:'005F0000003Ffzw'}" onblur="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onfocus="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);" onmouseout="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onmouseover="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);"><div class="feeditembestreplyheader"><img src="/forums/s.gif" alt=""  class="csFeedItemBestReplyByCustomerSupportIcon feedItemBestReplyIcon" />Best Answer chosen by Admin&nbsp;<span class="csCompanyNameTag">(Salesforce Developers)</span>&nbsp;<img src="/forums/s.gif" alt=""  class="agentIcon" /></div><div class="feeditemcommentbody"><span class="usericon"><img src="https://dfc-org-production.force.com/img/userprofile/default_profile_45_v2.png" alt="Ritesh Aswaney" width="30" height="30" class="cxuserimage" title="Ritesh Aswaney" /></span><strong class="feedText"><span class="feedcommentuser"><a href="https://dfc-org-production.force.com/forums/ForumsProfile?communityId=09aF00000004HMG&amp;userId=005F0000003Ffzw&amp;showHeader=false">Ritesh Aswaney</a></span><div class="feedcommenttext"><p>Its the URL Encoded value of the Forward Slash (/)</p><p> </p><p>Special characters need to be encoded in URL&#39;s, eg. +, &amp; , etc</p><p> </p><p><a href="http://www.blooberry.com/indexdot/html/topics/urlencoding.htm" target="_blank">http://www.blooberry.com/indexdot/html/topics/urlencoding.htm</a></p></div></strong><ul class="feeditemfooter"><li class="feeditemtimestamp">May 10, 2011</li><li class="feeditemreplysepdot1"> · </li><li class="cxlike" title="Like this"><a href="#" class="cxlikelink">Like</a></li><li class="upVoteCount" data-value="2">2</li><li class="feeditemreplysepdot2"> · </li><li class="cxdislike" title="Dislike this"><a href="#" class="cxdislikelink">Dislike</a></li><li class="downVoteCount" data-value="0">0</li></ul>
</div><div class="replyerrorcontainer" style="display:none"></div></div></div><div class="header"><h3>All Answers</h3></div><div class="cxfeedcomment csBestReplyInSIV cx907F00000008sS3 feeditemcomment" data-scc="{feedItemId:'907F00000008sS3IAI',ownerId:'005F0000003Ffzw'}" onblur="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onfocus="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);" onmouseout="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onmouseover="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);"><div class="feeditemcommentbody"><span class="usericon"><img src="https://dfc-org-production.force.com/img/userprofile/default_profile_45_v2.png" alt="Ritesh Aswaney" width="30" height="30" class="cxuserimage" title="Ritesh Aswaney" /></span><strong class="feedText"><span class="feedcommentuser"><a href="https://dfc-org-production.force.com/forums/ForumsProfile?communityId=09aF00000004HMG&amp;userId=005F0000003Ffzw&amp;showHeader=false">Ritesh Aswaney</a></span><div class="feedcommenttext"><p>Its the URL Encoded value of the Forward Slash (/)</p><p> </p><p>Special characters need to be encoded in URL&#39;s, eg. +, &amp; , etc</p><p> </p><p><a href="http://www.blooberry.com/indexdot/html/topics/urlencoding.htm" target="_blank">http://www.blooberry.com/indexdot/html/topics/urlencoding.htm</a></p></div></strong><div class="bestPlaceHolder">This was selected as the best answer</div></div><div class="replyerrorcontainer" style="display:none"></div></div><div class="cx907F000000090hU feeditemcomment cxfeedcomment" data-scc="{feedItemId:'907F000000090hUIAQ',ownerId:'005F0000003Firr'}" onblur="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onfocus="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);" onmouseout="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onmouseover="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);"><div class="feeditemcommentbody"><span class="usericon"><img src="https://dfc-org-production.force.com/img/userprofile/default_profile_45_v2.png" alt="Jeff Bloomer" width="30" height="30" class="cxuserimage" title="Jeff Bloomer" /></span><strong class="feedText"><span class="feedcommentuser"><a href="https://dfc-org-production.force.com/forums/ForumsProfile?communityId=09aF00000004HMG&amp;userId=005F0000003Firr&amp;showHeader=false">Jeff Bloomer</a></span><div class="feedcommenttext"><p>Here&#39;s another good resource on the topic.  It has a nice, long list for convenience.</p><p> </p><p><a href="http://www.w3schools.com/tags/ref_urlencode.asp" target="_blank" title="HTML URL Encoding Reference">http://www.w3schools.com/tags/ref_urlencode.asp</a></p></div></strong><ul class="feeditemfooter"><li class="feeditemtimestamp">July 17, 2013</li><li class="feeditemreplysepdot1"> · </li><li class="cxlike" title="Like this"><a href="#" class="cxlikelink">Like</a></li><li class="upVoteCount" data-value="0">0</li><li class="feeditemreplysepdot2"> · </li><li class="cxdislike" title="Dislike this"><a href="#" class="cxdislikelink">Dislike</a></li><li class="downVoteCount" data-value="0">0</li></ul>
</div><div class="replyerrorcontainer" style="display:none"></div></div></div><div class="cxnewcomment" style="display:none">
    <div class="cxcommententry feeditemcomment feeditemcommenttext">
        <div class="feeditemcommentnew">
<textarea  class="foobar cxnewcommenttext" id="" maxlength="32001" name="" tabindex="0" title="Write an answer or comment..." type="text" wrap="soft"></textarea>            <div class="cxvalidationmessage newcommenterrorcontainer" style="display:none"></div>
            <div>
                <input class="btn cxnewcommentaction newcommentbutton cxnewpublicreply" type="button" value="Answer" title="Answer" />
            </div>
            <div class="feedclearfloat"></div>
        </div>
    </div>
</div>
<div style="display:block" class="feeditemcommentplaceholder cxcommentplaceholder">
    <input type="text" readonly="true" value="Write an answer or comment..." class="cxcommentplaceholderaction" data-isPrivateConversation="false" />
</div></div></div></div></div></div></div></div><div id="cs:inlineSignIn" class="prompt" onclick="chatterService.getLogin().clearPrompt()" style="visibility: hidden">
    <h3>You need to sign in to do that.</h3>
    <div> 
        <strong>Need an account?</strong> 
        <a href="javascript:void(0);" id="cs:inlineSignUpButton">Sign Up</a>
    </div>
    <div class="last"> 
        <strong>Have an account?</strong>
            <a href="javascript:void(0);" id="cs:inlineSignInButton">Sign In</a>
    </div> 
    <a href="javascript:void(0);" id="cs:inlineDismiss" class="dismiss">Dismiss</a>
</div><div class="cxfooter">
    <ul id="cs:footer" class="">
            <li><a href="javascript:openPopupFocusEscapePounds(%27https://dfc-org-production.force.com/forums/ChatterAnswersHelp%27, %27Help%27, 1024, 768, %27width=1024,height=768,resizable=yes,toolbar=yes,status=yes,scrollbars=yes,menubar=yes,directories=no,location=yes,dependant=no%27, false, false);">Need help?</a></li>
    </ul>
</div>
<script>Ext.fly(window).on('load', function() {if ((window.sfdcPage) && (sfdcPage.executeOnloadQueue)){sfdcPage.executeOnloadQueue();};chatterService.getToolbox().setNoSignIn('false');chatterService.getToolbox().setSitePrefix('/forums');chatterService.getToolbox().setLanguage('en_US');chatterService.getToolbox().setIsHeaderRendered(false);chatterService.getToolbox().setProfilePageUrl('https://dfc-org-production.force.com/forums/ForumsProfile');chatterService.initFeeds({reputationEnabled:true,isTBEnabled:true,isRTEnabled:true,inPortal:false,loginPageUrl:'https://dfc-org-production.force.com/forums/ChatterAnswersLogin'}, {criteria:'BESTANSWERS',dataCategory:'Developer_Forums',communityId:'09aF00000004HMGIA2',jsApiPilot:'false',riutiz:'false',pp:'https://dfc-org-production.force.com/forums/ForumsProfile',baseUrl:'https://dfc-org-production.force.com/forums/'});});</script></span></div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            
            <div aria-hidden="true" aria-labelledby="categories_modal_Label" class="modal hide fade" id="categories_modal" role="dialog" tabindex="-1">
              <div class="modal-header">
                <button aria-hidden="true" class="close" data-dismiss="modal" type="button">&times;</button>
                <h3 id="categories_modal_Label">Select a category</h3>
              </div>
              <div class="modal-body">
                <div id="categories-modal-body"></div>
              </div>
            </div><!--<dfc-footer>-->
  <footer>
        <div class="footer-top">
            <div class="container">
                <div class="row small">
                    <div class="footerCols1">
                        <h3>
Get started                     </h3>
                        <ul class="unstyled">
                            <li>
                                <a href="/platform">
Salesforce App Cloud                                </a>
                            </li>
                            <li>
                                <a href="/gettingstarted">
Force.com                               </a>
                            </li>
                            <li>
                                <a href="https://devcenter.heroku.com/start">
Heroku                              </a>
                            </li>
                        </ul>
                    </div>
                    <div class="footerCols1">
                        <h3>
Salesforce Dev Centers                      </h3>
                        <ul class="unstyled">
                            <li>
                                <a href="/devcenter/lightning">
Lightning Developer Center                              </a>
                            </li>
                            <li>
                                <a href="/devcenter/mobile">
Mobile Developer Center                             </a>
                            </li>
                            <li>
                                <a href="http://devcenter.heroku.com/">
Heroku Dev Center                               </a>
                            </li>
                            <li>
                                <a href="http://dev.desk.com/">
Desk.com &lt;/developers&gt;                                </a>
                            </li>
                            <li>
                                <a href="http://developer.pardot.com/">
Pardot Developer Site                               </a>
                            </li>
                        </ul>
                    </div>
                    <div class="footerCols1">
                        <h3>
Developer resources                     </h3>
                        <ul class="unstyled">
                            <li>
                                <a href="/mobile">
Mobile Services                             </a>
                            </li>
                            <li>
                                <a href="javascript:window.location = '/docs/?service=Force.com&amp;sort=title'">
Force.com Docs                              </a>
                            </li>
                            <li>
                                <a href="/page/Tools">
Force.com Downloads                             </a>
                            </li>
                            <li>
                                <a href="javascript:window.location = '/docs/?service=Heroku'">
Heroku Docs                             </a>
                            </li>
                            <li>
                                <a href="http://toolbelt.heroku.com/">
Heroku Downloads                                </a>
                            </li>
                            <li>
                                <a href="/trailhead?utm_campaign=trailhead&amp;utm_source=website&amp;utm_medium=dsc_footer">
Learn Salesforce with Trailhead                             </a>
                            </li>
                        </ul>
                    </div>
                    <div class="footerCols1">
                        <h3>
Community                       </h3>
                        <ul class="unstyled">
                            <li>
                                <a href="/forums">
Developer Forums                                </a>
                            </li>
                            <li>
                                <a href="/calendar">
Salesforce Developer Events                             </a>
                            </li>
                            <li>
                                <a href="/content/type/Webinar">
Webinars                                </a>
                            </li>
                        </ul>
                    </div>
                    <div class="footerCols1">
                        <h3>
Learn more                      </h3>
                        <ul class="unstyled">
                            <li>
                                <a href="/appexchange">
Salesforce AppExchange                              </a>
                            </li>
                            <li>
                                <a href="//admin.salesforce.com">
Salesforce Administrators                               </a>
                            </li>
                            <li>
                                <a href="//help.salesforce.com/">
Salesforce.com Help Portal                              </a>
                            </li>
                        </ul>
                    </div>
                </div>
                <div class="row">
                    <div class="span9">
<!--<dfc-footer-copyright>-->                       <span class="footer-copyright">
© Copyright 2000-2016 salesforce.com, inc. All rights reserved. Various trademarks held by their respective owners.<br>Salesforce.com, inc. The Landmark @ One Market, Suite 300, San Francisco, CA 94105, United States                        </span>
<!--</dfc-footer-copyright>-->                      <div class="footer-links small">
                            <a href="//www.salesforce.com/company/privacy.jsp">
Privacy Statement                           </a>
                            <a href="//www.salesforce.com/company/security.jsp">
Security Statement                          </a>
                            <a href="/files/tos/Developerforce_TOU_20101119.pdf">
Terms of Use                            </a>
                            <a class="feedback" href="#" itemid="ebd396c9-3b7c-43bd-8223-419bc8a1cbeb">
<img src="//developer.salesforce.com/resource/images/opinionlab-orange.gif" alt="Feedback">Feedback                         </a>
                            <a href="http://www.salesforce.com/company/">
About Us                            </a>
                            <a class="language-switcher" href="javascript:void(0);">
Language:                               <span class="current-language">
English                                 </span>
                            </a>
                            <div class="language-switcher-popup hidden">
                                <h4 class="language-popup-title">
Choose a Language                               </h4>
                                <ul class="unstyled language-list">
                                    <li class="active" data-language="en">
English                                 </li>
                                    <li data-language="ja">
日本語                                 </li>
                                    <li data-language="fr">
Français                                    </li>
                                    <li data-language="de">
Deutsch                                 </li>
                                </ul>
                            </div>
                        </div>
                    </div>
                    <div class="span3">
                        <ul class="social-icons unstyled">
                            <li>
                                <a href="https://www.facebook.com/salesforcedevs">
<img src="//developer.salesforce.com/resource/images/facebook.png">                             </a>
                            </li>
                            <li>
                                <a href="https://twitter.com/#!/salesforcedevs">
<img src="//developer.salesforce.com/resource/images/twitter.png">                              </a>
                            </li>
                            <li>
                                <a href="https://plus.google.com/118327959233932983591">
<img src="//developer.salesforce.com/resource/images/g.png">                                </a>
                            </li>
                            <li>
                                <a href="https://www.linkedin.com/groups/Developer-Force-Forcecom-Community-3774731">
<img src="//developer.salesforce.com/resource/images/linkedIn.png">                             </a>
                            </li>
                            <li>
                                <a href="https://www.youtube.com/user/DeveloperForce">
<img src="//developer.salesforce.com/resource/images/youTube.png">                              </a>
                            </li>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
    </footer>
<script type="text/javascript" src="//developer.salesforce.com/resource/javascripts/footerbottom.min.js"></script>
<script type="text/javascript" src="/resource/javascripts/addthisconfig.min.js"></script>
<script type="text/javascript" src="//s7.addthis.com/js/300/addthis_widget.js#pubid=ra-5329fb0d17e1f4da"></script>
<!--</dfc-footer>--><!--<dfc-metrics>-->
<script type="text/javascript">
  // Google analytics 
  var _curLocationQuery = window.location.search.toLowerCase();
  if (!(
    _curLocationQuery.indexOf("un%3d") > -1 || 
    _curLocationQuery.indexOf("pw%3d") > -1 || 
    _curLocationQuery.indexOf("un=") > -1 || 
    _curLocationQuery.indexOf("pw=") > -1
  )) {
   var dataLayer = [];
   (function(w,d,s,l,i){
    w[l]=w[l]||[];w[l].push({'gtm.start':
   new Date().getTime(),event:'gtm.js'});
    var f=d.getElementsByTagName(s)[0],
      j=d.createElement(s),
      dl=l!=='dataLayer'?'&l='+l:'';
      
    j.async=true;
    j.src='//www.googletagmanager.com/gtm.js?id='+i+dl;
    f.parentNode.insertBefore(j,f);
   })(window,document,'script','dataLayer','GTM-MWZCN8');
  }
  
  // Adroll 
  adroll_adv_id = "KHANGVX5FNHJFGIKX7U7K5";
  adroll_pix_id = "ZDMR3ICVVVCZPHFRE3X6IU";
  (function () {
  var oldonload = window.onload;
  window.onload = function(){
     __adroll_loaded=true;
     var scr = document.createElement("script");
     var host = (("https:" == document.location.protocol) ? "https://s.adroll.com" : "http://a.adroll.com");
     scr.setAttribute('async', 'true');
     scr.type = "text/javascript";
     scr.src = host + "/j/roundtrip.js";
     ((document.getElementsByTagName('head') || [null])[0] ||
      document.getElementsByTagName('script')[0].parentNode).appendChild(scr);
     if(oldonload){oldonload()}};
  }());
</script>

<!--</dfc-metrics>-->
        <script src="//res.cloudinary.com/hy4kyit2a/raw/upload/qTip2_1.js" type="text/javascript"></script>
    </body>
</html>
<!DOCTYPE HTML><html class="js" lang="en" xmlns="http://www.w3.org/1999/xhtml">
    <head profile="http://gmpg.org/xfn/11">
<script src="/forums/static/111213/js/perf/stub.js" type="text/javascript"></script><script src="/forums/jslibrary/1479750578000/sfdc/main.js" type="text/javascript"></script><script src="/forums/jslibrary/jslabels/1479844900000/en_US.js" type="text/javascript"></script><script src="/forums/EXT/ext-3.0.0/ext-core.js" type="text/javascript"></script><script src="/forums/jslibrary/1479750578000/sfdc/ChatterAnswers.js" type="text/javascript"></script><script src="/ckeditor/ckeditor-4.x/rel/ckeditor.js?t=4.5.7" type="text/javascript"></script><script src="/forums/jslibrary/1479750578000/sfdc/ChatterAnswersJSAPI-1.0.js" type="text/javascript"></script><script src="/forums/jslibrary/1479750578000/sfdc/Zen.js" type="text/javascript"></script><link class="user" href="https://res.cloudinary.com/hy4kyit2a/raw/upload/qTip2.css" rel="stylesheet" type="text/css" /><link class="user" href="/forums/sCSS/38.0/sprites/1477585684000/Theme3/default/gc/common.css" rel="stylesheet" type="text/css" /><link class="user" href="/forums/sCSS/38.0/sprites/1477585684000/Theme3/default/gc/ChatterAnswers.css" rel="stylesheet" type="text/css" /><link class="user" href="/forums/sCSS/38.0/sprites/1477585684000/Theme3/default/gc/zen-select.css" rel="stylesheet" type="text/css" /><link class="user" href="/forums/sCSS/38.0/sprites/1477585684000/Theme3/default/gc/zen-componentsCompatible.css" rel="stylesheet" type="text/css" /><script src="/forums/jslibrary/1479750578000/sfdc/NetworkTracking.js" type="text/javascript"></script><script>try{ NetworkTracking.init('/forums/_ui/networks/tracking/NetworkTrackingServlet', 'network', '066F0000001KzEF'); }catch(x){}try{ NetworkTracking.logPageView();}catch(x){}</script><meta HTTP-EQUIV="PRAGMA" CONTENT="NO-CACHE" />
<meta HTTP-EQUIV="Expires" content="Mon, 01 Jan 1990 12:00:00 GMT" />

        
        <script src="//apis.google.com/js/plusone.js"></script>
        <script defer="defer" src="//platform.twitter.com/widgets.js"></script>
        <script src="//connect.facebook.net/en_US/all.js#xfbml=1&amp;appId=100816963337586"></script>
        <script src="//ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>

        
        <link href="/resource/stylesheets/syntax-highlighter.min.css" rel="stylesheet" type="text/css" />
        <script src="/resource/javascripts/syntax-highlighter.min.js"></script>

        <meta content="DeveloperForce" property="og:title" />
        <meta content="article" property="og:type" />
            <meta content="https://dfc-org-production.force.com/forums/?id=906F00000008pc4IAA" property="og:url" />
        <meta content="//res.cloudinary.com/hy4kyit2a/image/upload/sd_social300x300_1.png" property="og:image" />
        <meta content="DeveloperForce.com" property="og:site_name" />

        

        <style type="text/css">


            /* this is to copy to styles_min_7.css to fix an issue in search-query box SIZE, that does not appear in firebug or similar but need to be set */
            header .navbar .navbar-search .search-query {
                -moz-box-sizing: content-box;
                box-sizing: content-box;
            }
            /**/

            /* this is to overwrite the ChatterAnswers.css .facebook class */
            header .navbar .social-media .facebook{
                padding-left: 0px;
            }
            /**/

            /* this is to add a z-index property to the 'X' delete btn in comments */
            .csfeedcontainer .csdisableddelete, .csfeedcontainer .cxdeletelink {
                z-index: 9999;
            }

            .csfeedcontainer a {
                color: #048ec6 !important;
            }


            /* this is to fix an issue with nowrap in code tags */
            .feeditemcontent code {
                white-space: normal !important;
            }

            .csfeedcontainer .cxquestionheader .feeditemtext{
                margin-right: 0px !important;
            }


            /******** General styles *********/
            .datacategorylinks h3{
                color: #666;
                font-weight: normal;
                font-size: 16px;
                margin-bottom: 15px;
            }

            .datacategorylinks .csChildOption a {
                text-decoration: none;
                color: #048ec6;
                font-weight: bold;
                font-size: 13px;
                padding-left: 0;
            }
            .cacategorycounter{
                color: #555;
                font-weight: normal;
            }
            .datacategorylinks li a{
                color: #048ec6;
                padding: 0;
            }
            .cacategoymorelink li a{
                color: #048ec6;
                padding: none;
            }
            .cacategoymorelink{
                text-decoration: none;
                font-weight: bold;
                color: #048ec6;
                font-weight: bold;
                font-size: 13px;
            }
            .caleftnavseparator{
                width:100%;
                border-bottom: 1px solid #CCC;
                margin: 15px 0;
                clear: both;
            }
            #cs\:profile{
                float: left;
                margin: 0 0 10px;
            }
            #cs\:profile .username{
                display: none;
                /*margin-top: 10px;
                font-size: 13px !important;
                color: #0040ac;
                font-weight: bold;*/
            }
            .usericon, #cs\:profile .usericon {
                top: 100% !important;
                box-shadow: none;
                position: relative;
                margin-left: 0;
                padding-right: 15px;
            }
            .usericon .chatter-avatarStyle {
                display: none;
            }
            .usericon img {
                height: 27px;
                width: 27px;
            }
            .usericon {
                height: 27px;
                width: 27px;
            }
            .feeditemcommentbody{
                display: none !important;
            }
            .csCompanyNameTag{
                display: none;
            }
            .agentIcon{
                display: none;
            }
            .csfeedcontainer .feeditem {
                border: 1px solid #E8E8E8;
                padding: 0;
            }
            .feedcommentarrow{
                display: none !important;
            }
            .cxcomments .feeditemcomments{
                border: 1px solid #E8E8E8;
                padding: 20px 0;
            }
            .cxaddcommentaction{
                display: none;
            }
            .feeditemseparatingdot{
                display: none;
            }
            .csfeedcontainer .feeditem{
                box-shadow: -1px 2px 3px #b8b8b8 !important;
            }
            .csfeedcontainer .hideContext .csPreviewLinkContainer{
                display: none;
            }
            .csPreviewLinkContainer{
                display: none;
            }
            .showmorecommentscontainer{
                /*display: none;*/
            }
            .csfeedcontainer .feeditemcomment, .csfeedcontainer .feedcommentsshowmore, .feeditemcommentplaceholder, .csfeedcontainer{
                border: none;
            }
            .feeditembestreplyheader{
                margin: 5px 0 8px;
            }
            .feeditemcomment{
                padding: 0 8px;
            }
            .feeditemcomment .cxfeedcomment .cxfeedItemBestReplyText{
                width: 50%;
            }
            .cxsingleitemdetailfeed{
                color: #048ec6 !important;
                font-weight: normal !important;
            }
            .cxfeeditemcommentdot{
                display: none !important;
            }
            .csfeedcontainer .feeditemcontent {
                padding-left: 15px;
                padding-right: 0;
            }
            .prompt a{
                color: #048ec6 !important;
            }

            .cxSingleQuestionDetailFeed .feeditemcommentbody{
                display: block !important;
            }
            .cxSingleQuestionDetailFeed .feeditemcomment .usericon{
                width: 40px;
                height: 40px;
            }
            .cxSingleQuestionDetailFeed .feeditemcomment .usericon img{
                width: 40px;
                height: 40px;
            }

            .cxSingleQuestionResultFeed .feeditemcommentbody{
                display: block !important;
            }
            .cxSingleQuestionResultFeed .feeditemcomment .usericon{
                width: 40px;
                height: 40px;
            }
            .cxSingleQuestionResultFeed .feeditemcomment .usericon img{
                width: 40px;
                height: 40px;
            }

            .csfeedcontainer .feeditemcommentplaceholder input {
                color: #999999;
                height: 2.3em;
                min-height: 2.3em;
            }
            .cxSingleQuestionDetailFeed .cxcommentplaceholder input{
                border: 1px solid #e8e8e8;
                background: #ffffff;
                border-radius: 0;
            }
            .cxSingleQuestionDetailFeed .feeditemcomment{
                background: #ffffff;
                border-top: 1px solid #E8E8E8;
                padding: 25px 0 15px;
            }
            .cxSingleQuestionDetailFeed .cxfeedItemBestReplyText{
                background: #F0F8E2;
                padding-top: 10px;
                border: none;
            }
            /*.cxSingleQuestionDetailFeed .cxaddcommentaction{
                display: block;
                float: right;
            }*/
             .cxSingleQuestionDetailFeed .cxaddcommentaction{
                display: inline;
                margin: 0 2px 0 5px;
            }


            .cxSingleQuestionResultFeed .cxcommentplaceholder input{
                border: 1px solid #e8e8e8;
                background: #ffffff;
                border-radius: 0;
            }
            .cxSingleQuestionResultFeed .feeditemcomment{
                background: #ffffff;
                border-top: 1px solid #E8E8E8;
                padding: 25px 0 15px;
            }
            .cxSingleQuestionResultFeed .cxfeedItemBestReplyText{
                background: #F0F8E2;
                padding-top: 10px;
                border: none;
            }
            /*.cxSingleQuestionResultFeed .cxaddcommentaction{
                display: block;
                float: right;
            }*/
             .cxSingleQuestionResultFeed .cxaddcommentaction{
                display: inline;
                margin: 0 2px 0 5px;
            }
            .cxSingleQuestionDetailFeed .csBestReplyInSIV{
                display: none;
            }
            .cxSingleQuestionDetailFeed .feeditemcomments .header{
                display: none;
            }
            .cxSingleQuestionDetailFeed .feeditemfirstentity{
                margin-top: 19px;
            }
            .cxSingleQuestionDetailFeed .feeditemfooter{
                margin-left: 0px !important;
            }
            .cxSingleQuestionResultFeed .csBestReplyInSIV{
                display: none;
            }
            .cxSingleQuestionResultFeed .feeditemcomments .header{
                display: none;
            }
            .cxSingleQuestionResultFeed .feeditemfirstentity{
                margin-top: 19px;
            }
            .cxSingleQuestionResultFeed .feeditemfooter{
                margin-left: 0px !important;
            }


            .csMini .threecolumn {
                background: none;
                width: 1180px;
            }
            .threecolumn .leftContent{
                width: 220px;
                padding-left: 5px;
            }
            .threecolumn .centerContent{
                width: 920px;
            }

            .csMini .threecolumn .mainContent, .csMini .mainContent .lowerMainContent {
                float: left;
                width: 860px;
            }
            .threecolumn .mainContent {
                margin-left: 0;
            }
            .centerContent .csfeedcontainer {
                max-width: 920px;
            }
            /*.centerContent #cs\:searchAskForm.tbsearchAskForm {
                width: 721px;
            }*/
            .feeditemheader{
                color: #048ec6 !important;
                font-weight: normal;
            }
            .csfeedcontainer .cxquestionheader{
                margin-right: 0;
            }
            .csfeedcontainer .cxquestionheader .feeditemtext {
                margin-left: 15px;
                margin-right: 160px;
            }
            .cxSingleQuestionDetailFeed .cxquestionheader .feeditemtext{
                margin-left: 42px !important;
            }

            .cxSingleQuestionResultFeed .cxquestionheader .feeditemtext{
                margin-left: 42px !important;
            }


            .feeditemfooter{
                margin-left: 0;
                clear: both;
            }
            .cxSingleQuestionDetailFeed .feeditemfooter{
                margin-left: 42px;
            }


            .cxSingleQuestionResultFeed .feeditemfooter{
                margin-left: 42px;
            }


            .csMini #cs\:footer{
                display: none;
            }


            /**/
            .usericon{
                display: none;
            }
            #user_pic .usericon{
                display: block;
            }
            /**/


            .feeditemfirstentity{
                display: none;
            }

            .cxSingleQuestionDetailFeed .usericon{
                display: block;
            }
            .cxSingleQuestionDetailFeed .feeditemfirstentity{
                display: block;
            }


            .cxSingleQuestionResultFeed .usericon{
                display: block;
            }
            .cxSingleQuestionResultFeed .feeditemfirstentity{
                display: block;
            }


            .cxquestiontitlewithlink{
                margin-left: 0 !important;
            }
            .cxquestionbodypreview{
                margin-left: 0 !important;
            }
            .cxdeletelink {
                margin: 10px 0 0 0;
            }
            #cs:inlineSignIn{
                display: none;
                left: 72px !important;
            }
            .cxfooter{
                display: none;
            }
            .solved_container{
                display: block;
                float: right;
                text-align: center;
                margin: 15px 0 0 0;
                clear: both;
            }
            /*.solved_question{
                background: none repeat scroll 0 0 #009DDC;
                color: #FFFFFF;
                padding: 14px 18px;
            }*/
            .solved_question {
                background: none repeat scroll 0 0 #009DDC;
                border: 1px solid #327CBB;
                box-shadow: -1px 1px 2px #1963A2;
                color: #FFFFFF;
                margin-right: 5px;
                margin-bottom: 8px;
                padding: 14px 18px;
            }
            .solved_question_link:link, .solved_question_link:hover, .solved_question_link:visited{
                color: #FFFFFF;
                text-decoration: none;
            }
            .num_replies{
                color: #048ec6;
                padding-right: 8px;
            }
            .feeditemextras{
                display: none;
            }
            .cxSingleQuestionDetailFeed .feeditemextras{
                display: block;
            }


            .cxSingleQuestionResultFeed .feeditemextras{
                display: block;
            }


            .askContainer .tabs{
                height: 40%;
            }
            .leftContent .usericon{
                display: block;
            }
            #cs\:profile{
                padding-left: 0;
            }
            #cs\:profile .usericon{
                height: 40px;
                width: 40px;
            }
            #cs\:profile .usericon img {
                height: 40px;
                width: 40px;
            }
            .cxshowmorefeeditems{
                display: none;
            }
            .cxfollowlink{
                display: none;
            }
            .followCount{
                display: none !important;
            }
            .feeditemseparatingdot{
                visibility: hidden !important;
            }
            .cxquestionbodypreview{
                height: 60px;
                margin-left: 15px;
                overflow: hidden;
            }
            .cxquestionbodypreview p{
                margin: 0;
                line-height: 21px;
            }
            .cxSingleQuestionDetailFeed .cxquestionbodypreview{
                height: auto;
                overflow: inherit;
            }


            cxSingleQuestionResultFeed .cxquestionbodypreview{
                height: auto;
                overflow: inherit;
            }


            /*.cxSingleQuestionDetailFeed.cxcommentplaceholder{
                display: block !important;
            }*/
            .csoptimizequestion .cxquestiontitlewithlink, .csoptimizequestion h4.feeditemtext {
                margin-top: 0;
            }
            .custom_user_icon img{
                width: 25px;
                height: 25px;
            }
            .custom_user_icon{
                height: 25px;
                width: 25px;
                padding: 0 5px 0 0;
            }
            .user_profile_name{
                padding: 0 5px;
            }
            .user_profile_name a{
                text-decoration: none;
                font-weight: bold;
            }
            .searchContainer{
                background: none repeat scroll 0 0 #FFFFFF;
                border: 2px solid #E8E8E8;
                padding: 0 9px 4px;
            }
            .serviceCommunitySearchBox .searchbox {
                height: 43px;
                background-color: #E8E8E8 !important;
                border: none !important;
                border-radius: 0 !important;
            }
            .serviceCommunitySearchBox .searchtext{
                background: #e8e8e8 !important;
            }
            .serviceCommunityAskWidget .tabs {
                height: 5% !important;
            }
            .csfeedcontainer {
                line-height: 5px;
            }
            .cxmysettingslink{
                display: none !important;
            }
            /*.cxafterlike{
                display: none !important;
            }*/
            #forums_login_wrapper h3{
                font-size: 14px !important;
                line-height: 16px;
                margin-bottom: 0;
                color: #003FA9;
            }
            .csInfo{
                line-height: 16px;
            }
            #cs\:uploadLink{
                display: none !important;
            }
            #cs\:supportBubble{
                display: none !important;
            }
            .deflectionWrapper .filters{
                display: none;
            }
            .serviceCommunitySearchAskWidgetMain .msgbox{
                line-height: 28px;
            }
            .forums_social_media_container{
                float: right;
            }

            .forums_login_wrapper .forums_login{
                display: block;
                width: 118px;
                background: none repeat scroll 0 0 #FFFFFF;
                border: 1px solid #999;
                color: #2a97d4;
                padding: 10px 5px;
                text-decoration: none;
                background: #ffffff; /* Old browsers */
                background: -moz-linear-gradient(top,  #ffffff 0%, #e5e5e5 100%); /* FF3.6+ */
                background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,#ffffff), color-stop(100%,#e5e5e5)); /* Chrome,Safari4+ */
                background: -webkit-linear-gradient(top,  #ffffff 0%,#e5e5e5 100%); /* Chrome10+,Safari5.1+ */
                background: -o-linear-gradient(top,  #ffffff 0%,#e5e5e5 100%); /* Opera 11.10+ */
                background: -ms-linear-gradient(top,  #ffffff 0%,#e5e5e5 100%); /* IE10+ */
                background: linear-gradient(to bottom,  #ffffff 0%,#e5e5e5 100%); /* W3C */
                filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#ffffff', endColorstr='#e5e5e5',GradientType=0 ); /* IE6-9 */
            }
            .searchbutton .label{
                background: none;
            }

            .dont_have_account{
                font-size: 11px;
            }

            .signup_dev_edition{
                font-size: 11px;
                font-weight: bold;
                color: #048ec6;
            }

            .reg-sign-up_div{
                width: 162px;
                min-height: 25px;
                background-color: rgb(0,168,220);/* Old browsers */
                filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#00a8dc', endColorstr='#009aca',GradientType=0 ), dropshadow(color=#026786, offx=0, offy=-1); /* IE6-8 */
                background:url(data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiA/Pgo8c3ZnIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgd2lkdGg9IjEwMCUiIGhlaWdodD0iMTAwJSIgdmlld0JveD0iMCAwIDEgMSIgcHJlc2VydmVBc3BlY3RSYXRpbz0ibm9uZSI+CiAgPGxpbmVhckdyYWRpZW50IGlkPSJncmFkLXVjZ2ctZ2VuZXJhdGVkIiBncmFkaWVudFVuaXRzPSJ1c2VyU3BhY2VPblVzZSIgeDE9IjAlIiB5MT0iMCUiIHgyPSIwJSIgeTI9IjEwMCUiPgogICAgPHN0b3Agb2Zmc2V0PSIwJSIgc3RvcC1jb2xvcj0iIzAwYThkYyIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjQ5JSIgc3RvcC1jb2xvcj0iIzAwYThkYyIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjQ5JSIgc3RvcC1jb2xvcj0iIzAwOWFjYSIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjEwMCUiIHN0b3AtY29sb3I9IiMwMDlhY2EiIHN0b3Atb3BhY2l0eT0iMSIvPgogIDwvbGluZWFyR3JhZGllbnQ+CiAgPHJlY3QgeD0iMCIgeT0iMCIgd2lkdGg9IjEiIGhlaWdodD0iMSIgZmlsbD0idXJsKCNncmFkLXVjZ2ctZ2VuZXJhdGVkKSIgLz4KPC9zdmc+);
                background:-moz-linear-gradient(top,  rgba(0,168,220,1) 0%, rgba(0,168,220,1) 49%, rgba(0,154,202,1) 49%, rgba(0,154,202,1) 100%); /* FF3.6+ */
                background:-webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(0,168,220,1)), color-stop(49%,rgba(0,168,220,1)), color-stop(49%,rgba(0,154,202,1)), color-stop(100%,rgba(0,154,202,1))); /* Chrome,Safari4+ */
                background:-webkit-linear-gradient(top,  rgba(0,168,220,1) 0%,rgba(0,168,220,1) 49%,rgba(0,154,202,1) 49%,rgba(0,154,202,1) 100%); /* Chrome10+,Safari5.1+ */
                background:-o-linear-gradient(top,  rgba(0,168,220,1) 0%,rgba(0,168,220,1) 49%,rgba(0,154,202,1) 49%,rgba(0,154,202,1) 100%); /* Opera 11.10+ */
                background:-ms-linear-gradient(top,  rgba(0,168,220,1) 0%,rgba(0,168,220,1) 49%,rgba(0,154,202,1) 49%,rgba(0,154,202,1) 100%); /* IE10+ */
                background:linear-gradient(to bottom,  rgba(0,168,220,1) 0%,rgba(0,168,220,1) 49%,rgba(0,154,202,1) 49%,rgba(0,154,202,1) 100%); /* W3C */
                -webkit-border-radius:4px;
                border-radius:4px;
                -webkit-box-shadow: inset 0px 0px 0px 1px rgba(79, 195, 231, 1);
                box-shadow: inset 0px 0px 0px 1px rgba(79, 195, 231, 1);
                border:1px solid #0089b4;
                -moz-box-sizing: border-box;
                -webkit-box-sizing: border-box;
                box-sizing: border-box;
            }


            .reg-sign-up_div .cloudImg {
                background-image: url("//res.cloudinary.com/hy4kyit2a/image/upload/v1370270184/cv0c6vm49rfydoh4qpgv.png");
                float: left;
                height: 15px;
                width: 18px;
                margin: 4px 0 4px 10px;
            }

            .reg-sign-up_btn_div{
                width:122px;
                height:25px;
                float: right;
                -moz-box-sizing: border-box;
                -webkit-box-sizing: border-box;
                box-sizing: border-box;
                margin: 0 6px 0 0;
            }

            .reg-sign-up{
                font-family: ProximaNovaRegular;
                background-color: rgba(0, 0, 0, 0);
                background-color: transparent;
                margin: 0;
                padding: 0;
                font-weight: normal;
                font-style: normal;
                width:100%;
                height:25px;
                color:#ffffff;
                font-size:13px;
                border:0px;
                text-align: right;
                -moz-box-sizing: border-box;
                -webkit-box-sizing: border-box;
                box-sizing: border-box;
                text-shadow: 0px -1px 0px #0082a9;
            }

            .reg-sign-up_div:hover {
                filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#0285ad', endColorstr='#02799e',GradientType=0 ), dropshadow(color=#026786, offx=0, offy=-1); /* IE6-8 */

                background:rgb(2,133,173); /* Old browsers */
                /* IE9 SVG, needs conditional override of 'filter' to 'none' */
                background:url(data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiA/Pgo8c3ZnIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgd2lkdGg9IjEwMCUiIGhlaWdodD0iMTAwJSIgdmlld0JveD0iMCAwIDEgMSIgcHJlc2VydmVBc3BlY3RSYXRpbz0ibm9uZSI+CiAgPGxpbmVhckdyYWRpZW50IGlkPSJncmFkLXVjZ2ctZ2VuZXJhdGVkIiBncmFkaWVudFVuaXRzPSJ1c2VyU3BhY2VPblVzZSIgeDE9IjAlIiB5MT0iMCUiIHgyPSIwJSIgeTI9IjEwMCUiPgogICAgPHN0b3Agb2Zmc2V0PSIwJSIgc3RvcC1jb2xvcj0iIzAyODVhZCIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjQ5JSIgc3RvcC1jb2xvcj0iIzAyODVhZCIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjQ5JSIgc3RvcC1jb2xvcj0iIzAyNzk5ZSIgc3RvcC1vcGFjaXR5PSIxIi8+CiAgICA8c3RvcCBvZmZzZXQ9IjEwMCUiIHN0b3AtY29sb3I9IiMwMjc5OWUiIHN0b3Atb3BhY2l0eT0iMSIvPgogIDwvbGluZWFyR3JhZGllbnQ+CiAgPHJlY3QgeD0iMCIgeT0iMCIgd2lkdGg9IjEiIGhlaWdodD0iMSIgZmlsbD0idXJsKCNncmFkLXVjZ2ctZ2VuZXJhdGVkKSIgLz4KPC9zdmc+);
                background:-moz-linear-gradient(top,  rgba(2,133,173,1) 0%, rgba(2,133,173,1) 49%, rgba(2,121,158,1) 49%, rgba(2,121,158,1) 100%); /* FF3.6+ */
                background:-webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(2,133,173,1)), color-stop(49%,rgba(2,133,173,1)), color-stop(49%,rgba(2,121,158,1)), color-stop(100%,rgba(2,121,158,1))); /* Chrome,Safari4+ */
                background:-webkit-linear-gradient(top,  rgba(2,133,173,1) 0%,rgba(2,133,173,1) 49%,rgba(2,121,158,1) 49%,rgba(2,121,158,1) 100%); /* Chrome10+,Safari5.1+ */
                background:-o-linear-gradient(top,  rgba(2,133,173,1) 0%,rgba(2,133,173,1) 49%,rgba(2,121,158,1) 49%,rgba(2,121,158,1) 100%); /* Opera 11.10+ */
                background:-ms-linear-gradient(top,  rgba(2,133,173,1) 0%,rgba(2,133,173,1) 49%,rgba(2,121,158,1) 49%,rgba(2,121,158,1) 100%); /* IE10+ */
                background:linear-gradient(to bottom,  rgba(2,133,173,1) 0%,rgba(2,133,173,1) 49%,rgba(2,121,158,1) 49%,rgba(2,121,158,1) 100%); /* W3C */
                cursor:pointer;


                -webkit-box-shadow: inset 0px 0px 0px 1px rgba(80, 171, 231, 1);
                box-shadow: inset 0px 0px 0px 1px rgba(80, 171, 231, 1);
                text-shadow: 0px -1px 0px #026786;
            }

            /******** Forums categories component *******/
            #forums_categories_wrapper table tr td{
                border-collapse: collapse;
                border-bottom: solid 1px #E8E8E8;
                padding: 12px 30px 12px 0;
                font-size: 12px;
            }

            #forums_categories_wrapper .t_header{
                font-size: 14px;
                font-weight: normal;
            }

            #forums_categories_wrapper .t_header td{
                color: #2a97d4;
            }

            #forums_categories_wrapper .t_label{
                font-size: 13px;
                font-weight: bold;
            }

            #forums_categories_wrapper .t_count{
                font-size: 14px;
            }
            .forums_categories_detail_title{
                font-size: 15px;
            }

            .prompt {
                background: #eff7fa;

            }

            #discussion_board_topbar{
                background-color: #92d5f0;
            }

            .discussion_board_container{
                width: 1170px;
                margin: 0 auto;
            }
            .discussion_board_container:after{
                clear: both;
                content: ".";
                display: block;
                height: 0;
                visibility: hidden;
            }

            #discussion_board_title {
                float: left;
                font-size: 35px;
                padding: 30px 0;
                color: #152134;
            }
            .beta_banner_and_link{
                width: 35%;
                font-size: 18px;
                padding: 34px 0 0 10px;
                float: left;
                color: #152134;
            }

            .beta_banner_and_link a{
                font-size: 15px
            }

            .floated_button {
                float: left;
                width: 100px;
            }

            .user_reputation_green{
                background-color: #3CBE7C !important;
            }

            .user_reputation_blue{
                background-color: #8EA6D8 !important;
            }

            .user_reputation_violet{
                background-color: #65619D !important;
            }

            .user_reputation_orange{
                background-color: #D7823F !important;
            }

            .user_moderator_badge {
                background-color: #000 !important;
                margin-left: 5px;
            }

            @media (max-width: 1040px) {
                .discussion_board_container {
                    width: 90%;
                }

                .serviceCommunitySearchResult .stats{
                    float:none !important;
                }
                .serviceCommunitySearchResult .timestamp{
                    float:none !important;
                    height:auto !important;
                }
            }

            @media (max-width: 1024px) {
                .beta_banner_and_link{
                    display: none;
                }

                .serviceCommunitySearchResult .stats{
                    float:none !important;
                }
                .serviceCommunitySearchResult .timestamp{
                    float:none !important;
                    height:auto !important;
                }
            }

            @media (max-width: 700px) {
                #discussion_board_title {
                    float: none;
                    padding: 20px 0;
                    line-height: 30px;
                }

                .serviceCommunitySearchResult .stats{
                    float:none !important;
                }
                .serviceCommunitySearchResult .timestamp{
                    float:none !important;
                    height:auto !important;
                }
            }

            /* Landscape phones and down */
            @media (max-width: 448px) {
                .floated_button {
                    float: left;
                    width: 90px;
                }
                .prompt{
                    left: 0px !important;
                }
                .serviceCommunitySearchResult .stats{
                    float:none !important;
                }
                .serviceCommunitySearchResult .timestamp{
                    float:none !important;
                    height:auto !important;
                }
            }

            .header_false{
                background-color: #023F5E;
                height: 80px;
            }
            
            
            #main_profile_container .left_section {
                padding: 0;
                width: 200px;
            }
            
            #main_profile_container{
                padding: 10px 0 0 0;
                margin: auto;
                background: #FFFFFF;
                width: 1170px;
            }
            
            
            
            @media (min-width: 950px) {
                .feeditemcontent .read-more-link {
                    position: absolute;
                }
            }
            
            @media (min-width: 1450px) {
                #main_profile_container {
                    width: 1170px;
                }
            
                .row-fluid .span9{
                    margin-left: 50px;
                }
            
                /*.row-fluid .span9 {
                    width: 668px;
                }*/
            }
            
            @media (max-width: 1450px) {
                #main_profile_container .left_section {
                    padding: 0px;
                    /*margin: 0 0 0 30px;*/
                }
                
                .user_social {
                    margin: 0 auto;
                    width: 200px;
                }
            }
            
            @media (min-width: 521px) and (max-width: 1450px) {
                
                .profile_questions_container #user_stats{
                    width: intrinsic;
                    width: -moz-fit-content;
                    margin: 0 auto;
                }
            }
            
            @media (max-width: 1199px) {
                #main_profile_container{
                    width: 940px;
                }
            
                #profile_questions_container {
                    width: 720px;
                    margin: 0 0 0 20px;
                }
            }
            
            
            /* Portrait tablet to landscape and desktop */
            @media (min-width: 768px) and (max-width: 1450px) {
            
                #main_profile_container {
                    /*width: 94%;*/
                }
            
                /*.profile_questions_container #user_stats ul li{
                    margin: 0px 5px 0px 5px;
                    width: 170px;
                }*/
            
                .profile_questions_container #user_stats ul li.user_stats1 {
                    -moz-box-sizing: border-box;
                    box-sizing: border-box;
                    margin: 0 5px 0 0;
                }
            
                /*.......*/
            
                .row-fluid .span9 {
                    /*margin-left: 10px;*/
                    /*width: 674px;*/
                }
            }
            
            
            @media (max-width: 979px){
                #profile_questions_container {
                    width: 100%;
                    margin: 0 0 0 0;
                    float: none;
                }
                
                .contentArea .user_stats{
                    margin-top: 5px;
                }
                
                #user_stats ul li:last-child {
                    margin: 5px 0 0 0px !important;
                }
                
                #profile_details_container > #user_pic {
                    float: left;
                    margin-right: 8px;
                    margin-bottom: 8px;
                }
            
                .user_stats_list_container{
                    float: left;
                    margin-right: 30px;
                }
                
                .userprofile-sidebar-down ul.inline {
                    display: flex;
                }
                
                .userprofile-sidebar-down ul.unstyled {
                    display: table;
                }
            
                #main_profile_container .left_section {
                    width: 100%;
                    float: none;
                }
            
                /*.discussion_board_container{
                    width: 100%;
                }*/
            
                #cs\:theFeed{
                    padding: 10px 0 0;
                    margin-top: 10px;
                }
            
                .csfeedcontainer {
                    padding-bottom: 0;
                }
            
                .csfeedcontainer .feeditem {
                    margin: 0 0 10px;
                }
            
                .csfeedcontainer .cxquestionheader .feeditemtext {
                    margin-right: 0px;
                }
            
                .cxPopularFeed .cxfeeditem .cxfeeditemcontent {
                    padding-left: 10px !important;
                    padding-right: 10px;
                }
            
                h4.cxquestiontitlewithlink{
                    margin-bottom: 0px;
                }
            
                .cxquestionheader .cxquestionbodypreview.feeditemtext {
                    margin-top: 0;
                }
            
                .row-fluid .span9{
                    float: none;
                    margin: 0 auto;
                    clear: both;
                }
                
                .edit_profile_table{
                    margin: 0 auto;
                }
            }
            
            @media (min-width: 768px) and (max-width: 979px) {
                /* here */
                /*.discussion_board_container{
                    width: 750px;
                }*/
            
                /* HERE */
            
                #main_profile_container {
                    width: 96%;
                }
            }
            
            /* Landscape phone to portrait tablet */
            @media (min-width: 521px) and (max-width: 767px){
                #main_profile_container {
                    width: 94%;
                }
            
                .csMini .threecolumn .mainContent{
                    margin-left: 0px;
                }
            
                /*.discussion_board_container{
                    width: 974px;
                }*/
            
                .profile_questions_container #user_stats ul li .stats_number {
                    /*font-size: 20px;
                    line-height: 20px;*/
                }
            
                .profile_questions_container #user_stats ul li .stats_text {
                    /*font-size: 12px;
                    line-height: 12px;*/
                }
            
                .row-fluid .span9{
                    width: auto;
                }
            
                .profile_questions_container #user_stats{
                    width: 100%;
                }
            
                .profile_questions_container #user_stats ul li{
                    width: 20%;
                    margin: 0px 1% 0px 0px;
                    -moz-box-sizing: border-box;
                    box-sizing: border-box;
                }
            
                .profile_questions_container #user_stats ul li.user_stats1 {
                    width: 37%;
                    max-width: 37%;
                    margin: 0px 1% 0px 0px;
                    -moz-box-sizing: border-box;
                    box-sizing: border-box;
                }
            
                .profile_questions_container #user_stats ul li.user_stats:last-child {
                    margin: 0;
                }
            }
            
            
            @media (max-width: 658px){
            
            }
            
            
            /* Landscape phones and down */
            /* the real value is 448 but I need to set this in 520 */
            @media (max-width: 520px) {
            
                #main_profile_container {
                    width: 94%;
                }
            
                .row-fluid .span9{
                    width: auto;
                }
            
                .profile_questions_container #user_stats ul li{
                    /*width: 129px;
                    margin: 0px 5px 0px 0px;*/
                    margin: 0 1% 0 0;
                    width: 32%;
                    -moz-box-sizing: border-box;
                    box-sizing: border-box;
                }
            
                .profile_questions_container #user_stats ul li:last-child{
                    max-width: 35%;
                    min-width: 34%;
                    margin: 0;
                }
            
                .profile_questions_container #user_stats ul li.user_stats1{
                    width: 100%;
                    max-width: 100%;
                    -moz-box-sizing: border-box;
                    box-sizing: border-box;
                    margin: 0px 0px 3px 0px;
                    height: 48px;
                }
            
                /*.profile_questions_container #user_stats ul li .stats_number {
                    font-size: 20px;
                    line-height: 20px;
                }*/
            
                /*.profile_questions_container #user_stats ul li .stats_text {
                    font-size: 12px;
                    line-height: 12px;
                }*/
            }
            
            #navigation-bar h1 {
                font-size: 28px !important;
            }
        </style>

        <script>

            $( document ).ready(function() {
                if( $('div[id$="inlineSignIn"]').lenght != -1 ){
                    $('a[id$="inlineSignUpButton"]').click(function(){
                        document.location.href='/signup?d=70130000000tgM8';
                    });
                }
                if( $('div[id$="inlineSignIn"]').lenght != -1 ){
                    $('a[id$="inlineSignInButton"]').click(function(event){
                        event.preventDefault();
                        var href = window.location.href;
                        var index = href.indexOf('id=');
                        var id = href.substring(index);
                        var ref = '/forums/ForumsMain?'+ id;
                        document.location.href='/forums/CommunitiesLogin?startURL='+ ref;
                    });
                }


                var changeSignUpInterval;
                if( $('#searchInput').lenght != -1 ){
                    $('#searchInput').change(function(){
                        changeSignUpInterval = setInterval(function(){changeSignUpBtnLink()}, 100);
                    });
                }

                function changeSignUpBtnLink(){
                    if( $("a:contains('Sign Up')", $('.signinbox')).lenght != -1 ){

                        if( $("a:contains('Sign Up')", $('.signinbox')).is(':visible') ){

                            $("a:contains('Sign Up')").unbind();
                            $("a:contains('Sign Up')").click(function(){
                                document.location.href='/signup?d=70130000000tgM8';
                                $('#auraErrorMessage').hide();
                            });

                            clearInterval(changeSignUpInterval);
                        }
                    }
                }
            });
            
        </script><!--<dfc-head>-->

  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">

<link rel="icon" href="/resources2/favicon.ico" type="image/x-icon">
<link rel="shortcut icon" href="/resources2/favicon.ico" type="image/x-icon">
  <meta property="og:image" content="https://res.cloudinary.com/hy4kyit2a/image/upload/og-image.jpg" />
<link rel="stylesheet" type="text/css" href="/resources2/stylesheets/dsc-default-font.css?sv=18"/>

  <link href="//res.cloudinary.com/hy4kyit2a/image/upload/v1428517247/iphone_3_j0mhil.png" rel="apple-touch-icon-precomposed" type="image/png" />
  <link href="//res.cloudinary.com/hy4kyit2a/image/upload/v1428517247/iphone_3_j0mhil.png" rel="apple-touch-icon-precomposed" sizes="72x72" type="image/png" />
  <link href="//res.cloudinary.com/hy4kyit2a/image/upload/v1428517258/iphone-retina_ogf4ll.png" rel="apple-touch-icon-precomposed" sizes="114x114" type="image/png" />
  <link href="//res.cloudinary.com/hy4kyit2a/image/upload/v1428517265/ipad-retina_h8t1cu.png" rel="apple-touch-icon-precomposed" sizes="144x144" type="image/png" />


    <link href='/resource/stylesheets/holygrail.min.css' rel='stylesheet' type='text/css'/>
    <link rel="stylesheet" type="text/css" href="/resources2/stylesheets/dsc-default-font.css?sv=18"/>
<script type='text/javascript' src='/resource/javascripts/holygrail.min.js'></script>

<style>
    
</style>

<!--</dfc-head>-->
                    <link href="https://developer.salesforce.com/forums/?id=906F00000008pc4IAA" rel="canonical" />
                    <title>What does the "%2F" characters mean when used before an object in a URL? - Salesforce Developer Community</title>
                
                <script type="text/javascript">
                    var is_loggedin = false;
                    var is_moderator = false;
                    //Keep track of feed refresh to avoid multiple calls while scrolling
                    var feed_refresh_on = false;

                    Ext.onReady(function(){
                        drawSolvedReplies();
                        addReadMoreLink();
                        changeAnswerActionLabel();
                        changeQuestionSearchPlaceholder();
                        $("pre").addClass('syntaxhighlighter brush: VisualForce;');
                        runHighlighter();



                        Sfdc.on(chatterService.getFeed(), "chatterService:afterFeedRefresh", drawSolvedReplies);

                        //Sfdc.on(chatterService.getFeed(), "chatterService:afterFeedRefresh", updateFeedLinks );

                        //Sfdc.on(chatterService.getFeed(), "chatterService:afterFeedRefresh", changeSocialData);

                        Ext.Ajax.on('requestcomplete', function(conn,response,opts){
                            unfollow(opts);
                            task.delay(100);
                            task.delay(300);
                             //Adding css class for syntaxHighlighter after 300 ms
                            setTimeout(function(){
                                $("pre").addClass('syntaxhighlighter brush: VisualForce;');
                                runHighlighter();

                            },300);
                            //Init tootlip if user logged out
                            console.log('is_loggedin = '+is_loggedin);
                            if(!is_loggedin){
                                setQtip($('#discussion_button'), $('#login_prompt_button'));
                                $('#searchInput').prop('readonly',true);
                                $('.searchbutton.uiButton').attr('readonly',true);
                                setSearchQuestionField(0);
                            }
                            $('#searchQuestion').slideDown();
                        }, this);

                        // Follow a question after posting a reply
                        Ext.getBody().on('click', function (e) {
                            if (Ext.DomQuery.select('.cxunfollowlink').length === 0) {
                                followQuestionCallback(e.browserEvent);
                            }
                        }, this, {delegate: '.newcommentbutton.cxnewpublicreply'});

                        // Follow a question after clicking "Like"
                        $('.cxusefullink').live('click', function (e) {
                            followQuestionCallback(e);
                            return false;
                        });

                        var current_item;
                        $('.moderation_arrow').live('click', function(e){
                            current_item = $(e.target);
                            $(e.target).parent().parent().parent().parent().css('z-index', '500');
                            $(e.target).next('.moderation_dropdown').css('z-index', '2000');
                            $(e.target).next('.moderation_dropdown').show();
                        });

                        $(document).mouseup(function (e){
                            $(current_item).parent().parent().parent().parent().css('z-index', '0');
                            var container = $('.moderation_dropdown');

                            if (!container.is(e.target) && container.has(e.target).length === 0){
                                container.hide();
                            }
                        });

                        //Start a discussion button click listener
                        $('#discussion_button').click(function(){
                            if(is_loggedin){
                                var event = $A.get("e.serviceCommunity:proceedToPost");
                                    event.setParams({
                                    searchAskState: 2,
                                    query: "",
                                    guestUser: false
                                });
                                event.fire();
                            }else{
                                //Show login prompt
                            }
                        });
                    });

                    function setSearchQuestionField(count){
                      if($('#searchInput').length > 0){
                        setQtip($('.serviceCommunitySearchAskWidgetMain'), $('#login_prompt_search'));
                      }
                      else{
                        if(count<20){
                          setTimeout(setSearchQuestionField(count+1), 1500);
                        }
                      }
                    }
                    function setQtip(element, content_element){
                      element.qtip({
                        content: {
                            text: content_element.html()
                        },
                        position: {
                        my: "top center",
                            at: "bottom center"
                        },
                        style: {
                            classes: "qtip-df qtip-shadow qtip-rounded"
                        },
                        show: {event: 'click'},
                        hide: {event: "unfocus"}
                      });
                    }

                    var cookie_filters = '';
                    $(function () {

                        // Using jQuery's DOM-ready because of Ext's DOM-ready event being fired too late
                        // (maybe due to some AJAX request)



                        changeAnswerActionLabel();
                        if(is_moderator){
                            loadModerationDropdown();
                        }

                        $('.feedfilters li').click(function(){
                            setPreferredFilter($(this).find('a').attr('href'));
                        });

                        $('.feedsortby li').click(function(){
                            setPreferredFilter($(this).find('a').attr('href'));
                        });

                        var data_category;
                        var data_category_match = window.location.hash.match(/dc=(\w*)/);
                        typeof data_category_match == 'undefined' || data_category_match==null ? data_category = '' : data_category = data_category_match[0] + '&';

                        if(($.trim(cookie_filters) !== '') && !(/feedtype=SINGLE_QUESTION_DETAIL/.test(window.location.hash)) && ($('.cxthefeed').find('.cxSingleQuestionDetailFeed').length == 0) && ($('.cxthefeed').find('.cxSingleQuestionResultFeed').length == 0)) {
                            window.location.hash = '#!/' + data_category + cookie_filters;
                        } else if ($(".csfeedcontainer.cxSingleQuestionDetailFeed").size() == 0 && window.location.hash == '') {
                            window.location.hash = '#!/' + data_category + 'feedtype=RECENT&criteria=ALLQUESTIONS&';
                        }
                        navbar();

                        setNoFollowToLinks();
                    });

                    //Parses all ckeditor pre tags and changes the class to 'brush: VisualForce'
                    /*function parse_ckeditor_highlighter(){
                        jQuery.each($(".feeditemtext"), function(index,element){
                            var currentBody = $(element).html();
                            var reg = /(<pre ?.*?>)([\s\S]*?)(<\/pre>)/g
                            var matches = [];
                            var match;
                            while(match = reg.exec(currentBody)){
                                var auxmatch1 = match[1];
                                auxmatch1 = '<pre class="brush: VisualForce">';
                                currentBody = currentBody.replace(match[0], auxmatch1+match[2]+match[3]);
                                $(element).html(currentBody);
                            }
                        });
                    }*/

                    function unfollow(object) {
                        var url = object.url;
                        if(url && url.indexOf('Up') > 0) {
                            var id = url.substring(url.indexOf('vote/') + 5, url.indexOf('/Up'));
                            var nodeId = 'cx' + id.substring(0,15);

                            $('.' + nodeId) .find('.cxfollow').attr('title','Unfollow this question to stop receiving email updates');

                            $('.' + nodeId) .find('.cxfollow .cxfollowlink')
                                            .addClass('cxunfollowlink')
                                            .removeClass('cxfollowlink')
                                            .text('Unfollow')
                                            .show();

                            $('.' + nodeId) .find('.cxfollow .cxfollowing')
                                            .addClass('cxunfollowing')
                                            .removeClass('cxfollowing')
                                            .text('Unfolow');

                        }
                    }

                    function unescapePreTag(){
                        jQuery.each($(".feeditemtext"), function(index,element){
                            var currentBody = $(element).html();
                            var has_match = false;
                            var reg = /(&lt;pre ?.*?&gt;)(.*?)(&lt;\/pre&gt;)/g;
                            var matches = [];
                            var match;
                            while (match = reg.exec(currentBody)) {
                                var auxmatch1 = match[1];
                                var auxmatch3 = match[3];
                                auxmatch1 = auxmatch1.replace('&lt;', "<");
                                if(auxmatch1.indexOf('VisualForce')==-1){
                                    auxmatch1 = '<pre class="brush: VisualForce">';
                                }
                                auxmatch1 = auxmatch1.replace('&gt;', ">");
                                auxmatch3 = auxmatch3.replace('&lt;', "<");
                                auxmatch3 = auxmatch3.replace('&gt;', ">");
                                currentBody = currentBody.replace(match[0],auxmatch1+match[2]+auxmatch3);
                                has_match = true;
                            }
                            if(has_match){
                                currentBody = currentBody.replace(/<br>/g, "\n");
                                currentBody = currentBody.replace(/<br\/>/g, "\n");
                            }
                            $(element).html(currentBody);
                        });


                        jQuery.each($(".feedcommenttext"), function(index,element){
                            var currentBody = $(element).html();
                            var has_match = false;
                            var reg = /(&lt;pre ?.*?&gt;)(.*?)(&lt;\/pre&gt;)/g;
                            var matches = [];
                            var match;
                            while (match = reg.exec(currentBody)) {
                                var auxmatch1 = match[1];
                                var auxmatch3 = match[3];
                                auxmatch1 = auxmatch1.replace('&lt;', "<");
                                if(auxmatch1.indexOf('VisualForce')==-1){
                                    auxmatch1 = '<pre class="brush: VisualForce">';
                                }
                                auxmatch1 = auxmatch1.replace('&gt;', ">");
                                auxmatch3 = auxmatch3.replace('&lt;', "<");
                                auxmatch3 = auxmatch3.replace('&gt;', ">");
                                currentBody = currentBody.replace(match[0],auxmatch1+match[2]+auxmatch3);
                                has_match = true;
                            }
                            if(has_match){
                                currentBody = currentBody.replace(/<br>/g, "\n");
                                currentBody = currentBody.replace(/<br\/>/g, "\n");
                            }
                            $(element).html(currentBody);
                        });
                    }

                    function changeSocialData(text){
                        //var url ='//'+window.location.host+'/forums';
                        //var question_id = window.location.hash.match('[?&]id=([^&]+)') == null ? null : window.location.hash.match('[?&]id=([^&]+)')[1];
                        //if(question_id!=null && question_id!=''){
                        //  url = url + '/?id='+question_id;
                        //}
                        //$('#discussion_board_socialData .addthis_toolbox').attr('addthis:url', url);
                    }

                    var first_load = true;
                    function drawSolvedReplies(){
                        redraw_navbar();
                        if(is_moderator){
                            loadModerationDropdown();
                        }
                        jQuery.each($('.user_profile_name'), function(index, value){
                            var current_hostname = window.location.hostname;
                            var ahref = $(value).find('a');
                            var loc = document.createElement("a");
                            loc.href = $(ahref).attr('href');
                            loc.hostname = current_hostname;
                            $(ahref).attr('href', loc.href);

                        });
                        if(($('.cxthefeed').find('.cxSingleQuestionDetailFeed')==null || $('.cxthefeed').find('.cxSingleQuestionDetailFeed').length===0) && ($('.cxthefeed').find('.cxSingleQuestionResultFeed')==null || $('.cxthefeed').find('.cxSingleQuestionResultFeed').length===0)){
                            $('.cxfeeditemcontent').each(function(index, element){
                                window.document.title = 'Salesforce Developer Community';
                                var replies = 0;
                                if($(element).find('.num_replies')==null || $(element).find('.num_replies').length===0){

                                    //User image
                                    var user_icon = $(element).find(".usericon img").filter(":first");
                                    //User name
                                    var name = $(element).find('.feeditemfirstentity').html();
                                    //Container where the the two previous items will be apended
                                    var user_info = $(element).find('.feeditemfooter');

                                    //Prepend user picture and name to footer
                                    $(user_info).prepend(
                                        jQuery('<li>').append(
                                            jQuery('<div>')
                                                .addClass('user_profile_name')
                                                .append(name)
                                        )
                                    ).prepend(
                                        jQuery('<li>').append(
                                            jQuery('<div>')
                                                .addClass('custom_user_icon')
                                                .append(user_icon)
                                        )
                                    );

                                    var hash = $(element).find(".cxshowmorecomments").attr("data-scc");
                                    hash = "(" + hash + ")";
                                    hash = eval(hash);

                                    if(typeof hash === "undefined"){
                                        //console.info('hash undefined');
                                        if($(element).find('.cxbestReply').length > 0){
                                            replies = replies + 1;
                                        }
                                    }else{
                                        replies = hash.totalReplies;
                                    }

                                    var isSolved = false;
                                    if($(element).find('.feeditembestreplyheader').length>0){
                                        isSolved = true;
                                    }

                                    var html = $(element).find('.feeditemfirstentity');
                                    var title_link = $(element).find('.cxquestiontitlewithlink').find('.cxsingleitemdetailfeed').attr('href');

                                    var container = jQuery('<div>').addClass('solved_container');
                                    if(isSolved){
                                        container.append(
                                            jQuery('<a>').attr({"href" : title_link, "class" : "solved_question_link"}).append(
                                                jQuery('<div>').addClass('solved_question').append(
                                                    'SOLVED'
                                                )
                                            )
                                        );
                                    }
                                    container.append(
                                        jQuery('<a>').attr({href: title_link}).append(
                                            jQuery('<div>').addClass('num_replies').append(replies +' replies')
                                        )
                                    );
                                    html.after(container);

                                }

                            });
                            $('.feeditemextras').remove();
                            changeSocialData('#SalesforceDevs Discussion Forums - Q&A site for Salesforce admins, developers, architects & anybody in-between:');
                        }else{
                            window.document.title = $('.feeditemheader').text() + ' - Salesforce Developer Community';
                            changeSocialData('Can you answer this? ' + $('.feeditemheader').text() + ': (#SalesforceDevs)');
                            runHighlighter();
                        }
                        //ckeditor_to_syntax_highlighter();
                        changeAnswerActionLabel();
                        addReadMoreLink();
                        feed_refresh_on = false;
                        setNoFollowToLinks();
                        updateFeedLinks();
                        enableReplyArea();

                    }

                    function setNoFollowToLinks(){
                        // Adds nofollow value to rel attribute on every post containing links.
                        $('.cxthefeed div.feeditemtext.cxquestionbodypreview a').attr('rel','nofollow');
                        $('.cxthefeed div.feeditemcommentbody .feedcommenttext a').attr('rel','nofollow');
                        $('.cxthefeed').find('div.cxnotchatterlikesiv a').attr('rel','nofollow');
                    }

                    function updateFeedLinks(){

                      var userLink = $('.feeditemfirstentity a, .user_profile_name a');
                      var url = userLink.attr('href');
                      var splitUrl = url.split('forums');
                      url = location.origin + '/forums' + splitUrl[1];
                      userLink.attr('href',url);

                    }

                    function enableReplyArea(){
                        if(false){
                            $('.cxcommentplaceholderaction').click();
                        }
                    }

                    function changeAnswerActionLabel() {
                        $('.feeditem a.cxaddcommentaction').text('Reply');
                    }
                    function changeQuestionSearchPlaceholder() {
                        $('#searchInput').attr('Placeholder', 'Search or Ask a question to begin a discussion');
                    }

                    function getParameterByName(name) {
                        name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
                        var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
                            results = regex.exec(location);
                        return results === null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
                    }

                    function addReadMoreLink() {
                        $('.read-more-link').remove();

                        $('.feeditemtext.cxquestiontitlewithlink').each(function () {
                            var questionHref = $(this).find('a').attr('href');

                            var footer = $(this).closest('.feeditem').find('.feeditemfooter');

                            newReadMoreLinkNode(questionHref).appendTo(footer);
                        });
                    }

                    function newReadMoreLinkNode(questionHref) {
                        return jQuery('<li>')
                                    .append(jQuery('<a>').addClass('read-more-link').attr('href', questionHref).append('Continue reading or reply'));
                    }

                    // Traverses up the DOM from 'element' until the first .feeditem, and fetches feedItemId
                    function getQuestionId(element) {
                        var questionId = $(element).closest('.feeditem').data('scc').match("feedItemId:'([^']+)'");

                        return (questionId && questionId[1]) ? questionId[1] : null;
                    }

                    // Start following question
                    function followQuestion(id) {
                        $.get('/forums/forums_follow_post', {questionId: id})
                            //.success (function () {
                            //    // successful following question
                            //})
                            //.fail(function () {
                            //    // failed following question
                            //});
                    }

                    // Callback for events that require 'follow question' functionality
                    function followQuestionCallback(e){
                        var question_id = getQuestionId(e.target);

                        if (question_id) {
                            followQuestion(question_id)
                        }
                    }

                    /*function ckeditor_to_syntax_highlighter(){
                        parse_ckeditor_highlighter();
                        SyntaxHighlighter.highlight();
                    }*/

                    function runHighlighter(){
                        if( $('.bar', '.syntaxhighlighter').length > 0) {
                            SyntaxHighlighter.all();
                        }else{
                            unescapePreTag();
                            SyntaxHighlighter.config.clipboardSwf = '/resource/flash/clipboard.swf';
                            SyntaxHighlighter.highlight();
                        }
                    }

                    var task = new Ext.util.DelayedTask(function(){
                        drawSolvedReplies();
                    });

                    //Admin functions
                    function delete_post(question_id){
                        if(window.confirm("Are you sure you want to delete this post?")){
                            $.ajax({
                                type: 'GET',
                                url: '/forums/forums_delete_post',
                                data: {id: question_id}
                            }).done(function (data, status, xhr){
                                var question_card = $('.cx'+question_id.substring(0,15)+'.cxfeeditem');
                                question_card.fadeOut(500,
                                    function(){
                                        if($('.cxSingleQuestionDetailFeed').length===0){
                                            question_card.remove();
                                        }else{
                                            window.location.href='/forums';
                                        }
                                    });
                            });
                        }
                    }

                    function delete_reply(reply_id){
                        if(window.confirm("Are you sure you want to delete this reply?")){
                            $.ajax({
                                type: 'GET',
                                url: '/forums/forums_delete_reply',
                                data: {id: reply_id}
                            }).done(function (data, status, xhr){
                                var reply_div = $('.cx'+reply_id.substring(0,15)+'.feeditemcomment');
                                reply_div.fadeOut(500,
                                    function(){
                                        reply_div.remove();
                                    });
                            });
                        }
                    }

                    function change_category(question_id, category_name){
                        if(window.confirm("Are you sure you want change this post category?")){
                            $.ajax({
                                type: 'GET',
                                url: '/forums/forums_change_category',
                                data: {id: question_id, category: category_name}
                            }).done(function (data, status, xhr){
                                alert('Category changed');
                                $('#categories_modal').modal('hide');
                                if($('.cxSingleQuestionDetailFeed').length===0){
                                    window.location.reload();
                                }else{
                                    window.location.href='/forums?id='+question_id;
                                }
                            });
                        }
                    }

                    function list_datacategories(){
                        var dc_links = $('.cxdatacategory');
                        var list = [];
                        $.each(dc_links, function(index, value){
                            list[index] = $(value).data('dc');
                        });
                        list.sort();
                        return list;
                    }

                    function show_category_modal(question_id){
                        var categories = list_datacategories();
                        var container = jQuery('<div>').append(
                                            //jQuery('<h3>').text('Select a category')
                                        );
                        var list = jQuery('<ul>').addClass('categories_list');
                        $.each(categories, function(index, value){
                            list.append(
                                jQuery('<li>').append(
                                    jQuery('<a>').attr('href', 'javascript:change_category(\''+question_id+'\', \''+value+'\')').text(value.replace(/_/g, ' '))
                                )
                            );
                        });
                        container.append(list);
                        $('#categories-modal-body').html($(container));
                        $('#categories_modal').modal('show');
                    }

                    function loadModerationDropdown(){
                        /* Need to differentiate between question and comments to build
                            the dropdown with the right options for each one.
                        */
                        var questions = $('.cxfeeditem');
                        var comments = $('.cxfeedcomment');
                        var question_id = '';
                        $.each(questions, function(index, value){
                            //Build dropdown with change category
                            question_id = $(value).data('scc').match("feedItemId:'([^']+)'")[1];
                            if($('.cxthefeed').find('.cxSingleQuestionDetailFeed').length>0 && first_load){
                                first_load = false;
                                var replaceable_element = $(value).find('.cxreportabuseaction').filter(':first');
                                var f = buildModerationDropdown(replaceable_element, question_id, true);
                                $(replaceable_element).replaceWith(f);
                            }else{
                                if($('.cxthefeed').find('.cxSingleQuestionDetailFeed').length==0){
                                    first_load = true;
                                    var replaceable_element = $(value).find('.cxreportabuseaction').filter(':first');
                                    var f = buildModerationDropdown(replaceable_element, question_id, true);
                                    $(replaceable_element).replaceWith(f);
                                }
                            }
                        });

                        $.each(comments, function(index, value){
                            //Build dropdown without change category
                            var reply_id = $(value).data('scc').match("feedItemId:'([^']+)'")[1];
                            var replaceable_element = $(value).find('.cxreportabuseaction');
                            var f = buildModerationDropdown(replaceable_element, reply_id, false);
                            $(replaceable_element).replaceWith(f);
                        });

                    }

                    function buildModerationDropdown(value, question_id, is_question){
                        var dropdown = jQuery('<li>').addClass('moderation_item').append(
                                            jQuery('<a>').attr('href', 'javascript:void(0)').text('Moderate').addClass('moderation_arrow'));
                        var drop_list = jQuery('<ul>').addClass('moderation_dropdown');
                        var drop_item_1;
                        if(is_question){
                             drop_item_1 = jQuery('<li>').append(
                                            jQuery('<a>').attr('href', 'javascript:delete_post(\''+question_id+'\')').text('Delete')
                                        );
                            var drop_item_2 = jQuery('<li>').append(
                                                jQuery('<a>').attr('href', 'javascript:show_category_modal(\''+question_id+'\')').text('Change category')
                                            );
                            drop_item_2.appendTo(drop_item_1);
                        }else{
                            drop_item_1 = jQuery('<li>').append(
                                            jQuery('<a>').attr('href', 'javascript:delete_reply(\''+question_id+'\')').text('Delete')
                                        );
                            //if($('.cxthefeed').find('.feeditembestreplyheader').length===0){
                                var drop_item_3 = jQuery('<li>').append(
                                                    jQuery('<a>').attr('href', '/forums/forums_best_answer?id='+question_id).text('Best answer')
                                                );
                                drop_item_3.appendTo(drop_item_1);
                            //}
                        }
                        drop_list.append(drop_item_1).appendTo(dropdown);
                        return dropdown;
                    }

                    function setPreferredFilter(filter_params){
                        $.ajax({
                            type: 'GET',
                            url: '/forums/ForumsSetFiltersCookie',
                            data: {filters: filter_params}
                        }).done(function (data, status, xhr){
                            //console.info('Done setting the cookie');
                        });
                    }

                    function redraw_navbar(){
                        var title = '#SalesforceDevs Discussion Forums - Q&A site for Salesforce admins, developers, architects & anybody in-between:';
                        //var question_tweet_text = 'Can you answer this? Portal login Apex code doesn\'t send password email: (#SalesforceDevs)';
                        var question_tweet_text = 'Can you answer this? ';

                        var url ='//'+window.location.host+'/forums';
                        var breadcrumbs = $($('#navigation-bar .span9')[0]).children().first();
                        if(($('.cxthefeed').find('.cxSingleQuestionDetailFeed')==null || $('.cxthefeed').find('.cxSingleQuestionDetailFeed').length===0) && ($('.cxthefeed').find('.cxSingleQuestionResultFeed')==null || $('.cxthefeed').find('.cxSingleQuestionResultFeed').length===0)){
                            var data_category_match = window.location.hash.match(/dc=(\w*)/)
                            if(typeof data_category_match != 'undefined' && data_category_match!=null && data_category_match[1]!='Developer_Forums'){
                                breadcrumbs.html(
                                    jQuery('<div>').addClass('show').append(
                                        jQuery('<a>').attr('href', '/').text('Home')
                                    ).append(
                                        '&#160;&#187;&#160;'
                                    ).append(
                                        jQuery('<a>').attr('href', '/forums').text('Discussion Forums')
                                    ).append(
                                        '&#160;&#187;&#160;'
                                    ).append(
                                        jQuery('<h1>').text(categories_name[data_category_match[1]])
                                    )
                                );

                                var params = '';
                                if(getParameterByName('dc') !=  '') {
                                    params = '?dc=' + getParameterByName('dc');
                                }

                                url = window.location.protocol + url + params;
                                $('link[rel="canonical"]').attr('href',url);
                            }else{
                                breadcrumbs.html(
                                    jQuery('<div>').addClass('show').append(
                                        jQuery('<a>').attr('href', '/').text('Home')
                                    ).append(
                                        '&#160;&#187;&#160;'
                                    ).append(
                                        jQuery('<h1>').text('Discussion Forums')
                                    )
                                );

                                var params = '';
                                if(getParameterByName('dc') !=  '') {
                                    params = '?dc=' + getParameterByName('dc');
                                }

                                url = window.location.protocol + url + params;
                                $('link[rel="canonical"]').attr('href',url);
                            }
                        }else{
                            breadcrumbs.html(
                                jQuery('<div>').addClass('show').append(
                                    jQuery('<a>').attr('href', '/').text('Home')
                                ).append(
                                    '&#160;&#187;&#160;'
                                ).append(
                                    jQuery('<a>').attr('href', '/forums').text('Discussion Forums')
                                ).append(
                                    '&#160;&#187;&#160;'
                                ).append(
                                    jQuery('<h1>').text($('.feeditemheader').text())
                                )
                            );
                            title = question_tweet_text + ' ' + document.title;
                            //var question_id = window.location.hash.match('[?&]id=([^&]+)') == null ? null : window.location.hash.match('[?&]id=([^&]+)')[1];
                            var question_id = window.location.href.match('[?&]id=([^&]+)') == null ? null : window.location.href.match('[?&]id=([^&]+)')[1];
                            if(question_id!=null && question_id!=''){
                                url =  window.location.protocol + url + '/?id='+question_id;
                                $('link[rel="canonical"]').attr('href',url);
                            }
                        }
                        addthis.update('share', 'url', url);
                        addthis.update('share', 'title', title);
                    }

                    function navbar(){
                        var title = '#SalesforceDevs Discussion Forums - Q&A site for Salesforce admins, developers, architects & anybody in-between:';
                        //var question_tweet_text = 'Can you answer this? Portal login Apex code doesn\'t send password email: (#SalesforceDevs)';
                        var question_tweet_text = 'Can you answer this? ';

                        var url ='//'+window.location.host+'/forums';
                        if (typeof(updateNavBar) == 'function') {
                            var element = $('#navigation-bar .span9')[0];
                            var breadcrumbs = [];

                            var hash;

                            breadcrumbs.push(
                            {
                                href: '/',
                                text: 'Home'
                            })

                            if(($('.cxthefeed').find('.cxSingleQuestionDetailFeed')==null || $('.cxthefeed').find('.cxSingleQuestionDetailFeed').length===0) && ($('.cxthefeed').find('.cxSingleQuestionResultFeed')==null || $('.cxthefeed').find('.cxSingleQuestionResultFeed').length===0)){
                                //breadcrumbs.push('Discussion Forums');
                                hash = {
                                    'nav-title': 'Discussion Forums'
                                };
                            }else{
                                title = question_tweet_text + ' ' + document.title;
                                hash = {
                                    'nav-title': encodeURI($('.feeditemheader').text())
                                };
                                breadcrumbs.push(
                                    {
                                        href: '/forums',
                                        text: 'Discussion Forums'
                                    }
                                );
                                //breadcrumbs.push('Question detail');

                                var question_id = window.location.hash.match('[?&]id=([^&]+)') == null ? null : window.location.hash.match('[?&]id=([^&]+)')[1];
                                if(question_id!=null && question_id!=''){
                                    url = url + '/?id='+question_id;
                                }

                        //}
                            }

                            hash['show-breadcrumb'] = 'show';
                            hash['no-breadcrumb'] = '';
                            updateNavBar(element, hash, breadcrumbs);
                            addthis.update('share', 'url', url);
                            addthis.update('share', 'title', title);
                        }
                    }

                    $(window).scroll(function(){
                        var mobile_size = $("header").height() + $("#discussion_board_topbar").height() + $(".csMini").height() - ($("footer").height()/2);
                        var web_size = $(document).height() - $(window).height();
                        var current = $(window).scrollTop();
                        if(current + 1000 >= mobile_size || current + 600 >= web_size){
                            if($('.cxshowmorefeeditems')!=null && $('.cxshowmorefeeditems').length>0 && !feed_refresh_on){
                                feed_refresh_on = true;
                                chatterService.getFeed().showMoreFeedItems('click', Ext.select('.cxshowmorefeeditems').elements[0]);
                            }else{
                                //No more questions to load
                            }
                        }
                    });
                </script>

                <style>
                    /******* Override general styles from lunch *********/
                    body{
                        font-size: 12px;
                        line-height: 16px;
                    }

                    h1, h2, h3, h4, h5, h6 {
                        color: inherit;
                        font-weight: bold;
                        line-height: 0;
                    }

                    h4 {
                        font-size: 13px;
                    }
                    p {
                        margin: 0;
                    }


                    textarea, input[type="text"], input[type="password"], input[type="datetime"], input[type="datetime-local"], input[type="date"], input[type="month"], input[type="time"], input[type="week"], input[type="number"], input[type="email"], input[type="url"], input[type="search"], input[type="tel"], input[type="color"], .uneditable-input {
                        background-color: none;
                        border: none;
                        box-shadow: none;
                        transition: none;
                    }

                    select, textarea, input[type="text"], input[type="password"], input[type="datetime"], input[type="datetime-local"], input[type="date"], input[type="month"], input[type="time"], input[type="week"], input[type="number"], input[type="email"], input[type="url"], input[type="search"], input[type="tel"], input[type="color"], .uneditable-input {
                        border-radius: 0;
                        margin-bottom: 0;
                        padding: 0;
                    }

                    .label{
                        background-color: none;
                        border-radius: none;
                    }

                    .overlayDialog{
                        width: 480px !important;
                    }
                    #ChatterServiceDeleteConfirmationFocusPoint {
                        white-space: nowrap;
                    }

                    /**/

                    /*.scrn_mobile{
                        display: none;
                    }
                    .scrn_standard{
                        display: block;
                    }

                    .scrn_mobile_title{
                        widht: 200px;
                    }

                    .forums_fb_button {
                        margin-right: 0px;
                    }

                    .cxthefeed {
                        clear: none;
                    }*/

                    /*.forums_social_media_container:after{
                        clear: both;
                        content: ".";
                        display: block;
                        height: 0;
                        visibility: hidden;
                    }*/

                    .threecolumn:after{
                        clear: both;
                        content: ".";
                        display: block;
                        height: 0;
                        visibility: hidden;
                    }
                    .threecolumn .mainContent{
                        margin-left: 20px;
                    }
                    .threecolumn .lowerMainContent .centerContent {
                        padding-left: 0px;
                    }

                    .threecolumn .centerContent{
                        float: none;
                    }

                    #discussion_board_topbar{
                        background-color: #92d5f0;
                    }

                    /*.discussion_board_container{
                        width: 974px;
                        margin: 0 auto;
                    }
                    .discussion_board_container:after{
                        clear: both;
                        content: ".";
                        display: block;
                        height: 0;
                        visibility: hidden;
                    }*/

                    .cxquestionheader .feeditemtext.cxquestionbodypreview div{
                        height: 40px;
                    }

                    .feeditemcontent .read-more-link {
                        position: static;
                        display: block;
                        right: 9px;
                        bottom: 0;
                    }

                    @media (min-width: 950px) {
                        .feeditemcontent .read-more-link {
                            position: absolute;
                        }
                    }

                    @media (max-width: 1040px) {

                        .csMini .threecolumn {
                            width: 94%;
                        }

                        .csMini .threecolumn .mainContent{
                            float: none;
                            width: auto;
                            margin-left: 230px;
                        }

                        .csMini .mainContent .lowerMainContent {
                            width: 91%;
                        }

                        .threecolumn .centerContent {
                            width: 100%;
                        }
                    }

                    @media (max-width: 970px) {

                        .csMini .threecolumn {
                            width: 92%;
                        }

                    }

                    @media (max-width: 767px){

                        /*.discussion_board_container{
                            width: 100%;
                        }

                        .discussion_board_container{
                            width: 100%;
                        }*/

                        .csMini .threecolumn .mainContent{
                            margin-left: 0px;
                        }

                        #cs\:theFeed{
                            padding: 10px 0 0;
                            margin-top: 10px;
                        }

                        .csfeedcontainer {
                            padding-bottom: 0;
                        }

                        .csfeedcontainer .feeditem {
                            margin: 0 0 10px;
                        }

                        .csfeedcontainer .cxquestionheader .feeditemtext {
                            margin-right: 0px;
                        }

                        .cxPopularFeed .cxfeeditem .cxfeeditemcontent {
                            padding-left: 10px !important;
                            padding-right: 10px;
                        }

                        h4.cxquestiontitlewithlink{
                            margin-bottom: 0px;
                        }

                        .cxquestionheader .cxquestionbodypreview.feeditemtext {
                            margin-top: 0;
                        }
                    }


                    @media (max-width: 610px){

                        .threecolumn .leftContent {
                            width: 100%;
                        }

                        .csMini .threecolumn .mainContent {
                            clear: both;
                            float: none;
                            margin-left: 0px;
                            width: auto;
                        }
                    }

                    @media (min-width: 768px) and (max-width: 979px) {
                        /* here */
                        /*.discussion_board_container{
                            width: 750px;
                        }*/
                    }

                    /* Landscape phones and down */
                    /*@media (max-width: 448px) {
                        .scrn_mobile{
                            display: block;
                        }
                        .scrn_standard{
                            display: none;
                        }
                    }*/

                    .serviceCommunityDeflectionActions .actions .proceedtopost button.uiButton{
                        background: none repeat scroll 0 0 #31A3E0 !important;
                        border: 0 !important;
                        box-shadow: none !important;
                    }

                    .serviceCommunityDeflectionActions .actions .proceedtopost button.uiButton span{
                        background: transparent;
                    }

                    .serviceCommunityAskWidget .buttonbox button.cancelbutton{
                        background: #cccccc;
                        border: 0;
                        margin-right: 10px;
                    }

                    .serviceCommunityAskWidget .buttonbox button.postbutton.uiButton{
                        background: none repeat scroll 0 0 #31A3E0 !important;
                        border: 0 !important;
                        box-shadow: none !important;
                    }

                    .serviceCommunityAskWidget .buttonbox button.cancelbutton span, .serviceCommunityAskWidget .buttonbox button.postbutton.uiBlock span{
                        background: transparent;
                    }

                    .cafiltersupermenu{
                        float: left;
                    }

                    .cafiltersupermenu.zen .zen-options a:hover,
                    .cafiltersupermenu.zen .zen-options a:focus {
                        color: #048ec6;
                    }

                    .facet.facetheader.filterHeader h4,
                    .facet.facetheader.sortByHeader h4 {
                        color: #01344e;
                    }

                    .start_button{
                        float: right;
                        text-align: center;
                        line-height: 25px;
                        margin: 0 5px 0 0px !important;
                        padding: 7px 10px;
                        width: 200px !important;
                        -moz-box-sizing: border-box;
                        box-sizing: border-box;
                        background-image: linear-gradient(to bottom, #FFFFFF 0%, #EFEFEF 100%);
                        margin: 0px 5px 0px 5px;
                        width: 142px;
                        border: 1px solid #A7A7A7;
                        font-size: 18px;
                        color: #048ec6;
                        cursor: pointer;
                    }

                    .qtip-df{
                        background: #ffffff;
                        border: 1px solid rgb(0,168,220);
                        font-size: 14px;
                        line-height: 14px;
                    }

                    .moderation_controls{
                        float:right;
                    }

                    .moderation_arrow{
                        background: url(/img/chatterservice/btnArrow_sprite.png) no-repeat scroll right -55px transparent;
                        padding: 0 18px 0 0;
                    }

                    .moderation_dropdown{
                        display: none;
                        text-align: left;
                        position: absolute;
                        left: 0;
                        top: 19px;
                        border: 1px solid #b6b6b6;
                        margin: 0;
                        padding: 4px;
                        background-color: #fff;
                        -webkit-border-radius: 5px;
                        -moz-border-radius: 5px;
                        border-radius: 5px;
                        -webkit-box-shadow: 0 2px 5px #a0a6ab;
                        -moz-box-shadow: 0 2px 5px #a0a6ab;
                        box-shadow: 0 2px 5px #a0a6ab;
                    }

                    .moderation_dropdown li{
                        float: left;
                        clear: both;
                    }

                    .moderation_dropdown a{
                        height: 12px;
                        padding: 4px 9px;
                        text-align: left;
                        cursor: pointer;
                        line-height: 1em;
                        color: #222;
                        white-space: nowrap;
                        -webkit-border-radius: 9px;
                        -moz-border-radius: 9px;
                        border-radius: 9px;
                        font-size: 1.25em !important;
                    }

                    .moderation_dropdown a:hover{
                        background-color: #cfeef8;
                        color: #015ba7;
                        cursor: pointer;
                    }

                    .moderation_item{
                        position: relative;
                    }

                    #simplemodal-overlay{
                        background-color: #31A3E0 !important;
                    }

                    .categories_list{
                        margin-top: 10px;
                        padding: 0;
                        list-style: none;
                    }

                    .categories_list li{
                        margin: 0;
                        padding: 2px 0;
                    }

                    .categories_list a{
                        text-decoration: none;
                        color: #2a97d4;
                        font-weight: bold;
                        font-size: 11px;
                    }

                    .csfeedcontainer .feeditem{
                        z-index: 0;
                    }

                    .ui-widget-overlay{
                        background-color: #31A3E0;
                    }

                    .ui-dialog{
                        background-color: #fff;
                        border-color: #2a97d4;
                        border-radius: 10px;
                        padding: 35px;
                        box-shadow: 0px 0px 10px #888;
                    }

                    .modal-backdrop{
                        background: #aaaaaa;
                        opacity: 0.3;
                    }

                    .modal-header .close {
                        margin-top: 8px;
                        right: 0px;
                    }

                    #filterDisplay, #sortDisplay {
                        color: #048ec6;
                    }

                    .feeditemtext.cxquestionbodypreview,
                    .feedcommenttext,
                    div.feeditemtext.cxnotchatterlikesiv {
                        font-size: 14px;
                    }

                    .feeditemcontent.cxfeeditemcontent li.feeditemtimestamp {
                        font-size: 14 !important;
                    }
                </style>

                <style>
                    .feeditemtext div,
                    .feeditemtext span,
                    .feeditemtext p,
                    .feeditemtext a{
                        font-family: ProximaNovaRegular !important;
                        font-size: 15px !important;
                    }
                    .feeditemtext a,
                    .feeditemtext a *{
                        color: #048ec6 !important;
                    }
                    h4.feeditemtext a {
                        font-size: 1.3em !important;
                    }
                    .datacategorylinks .csChildOption a {
                        font-size: 15px;
                        font-weight: normal;
                    }
                    .cxquestionheader .feeditemtext.cxquestionbodypreview div {
                        height: auto;
                    }
                    .feeditemtext.cxquestionbodypreview {
                        height: auto;
                        max-height: 67px;
                    }
                    .csfeedcontainer .feeditemcontent {
                        padding-left: 15px;
                        padding-right: 15px;
                    }

                    #searchInput:focus{
                      box-shadow:  none;
                    }
                    
                    .searchbutton.uiButton--default.uiButton{
                       border: none;
                       box-shadow: none;
                    }
                    .searchbutton.uiButton--default.uiButton[readonly]{
                       cursor: not-allowed;
                    }
                    /* hiding the button until the issue with proceedToPost event gets fixed */
                    #discussion_button{
                      display: none;
                    }
                </style>
        
        <link href="/resource/stylesheets/profile.min.css" rel="stylesheet" type="text/css" />

    </head>

    <body>

        <img src="//res.cloudinary.com/hy4kyit2a/image/upload/sd_social300x300_1.png" style="display: none;" />

        <header><!--<dfc-header>-->
<!--<script type="text/javascript" src="/custom.js"></script>-->
    <div class="navbar navbar-static-top">
            <div class="navbar-inner">
                <div class="container">
                    <div class="mobileHeaderContainer">
                        <a class="brand clearfix" href="/"><img src="/resources2/images/salesforce-header-logo.png" class="sewg314"/></a>
                        <div class="headerButtonsContainer">
                            <div class="spanButton clearfix pull-right">
                                <a class="btn btn-success" type="button" href="/signup?d=70130000000td6N">
Sign Up &rsaquo;                                </a>
                            </div>
                            <div style="position: relative;" class="spanButton clearfix pull-right">
                                <BUTTON id="login-button" class="btn btn-primary" type="button">
Login &rsaquo;                              </BUTTON>
                                <div id="user-info-container" style="display: none;">
                                    <div id="user-info-content">
                                        <div id="user-info-header" class="clearfix">
                                            <div id="user-info-picture">
&nbsp;                                          </div>
                                            <div id="user-info-text-container">
                                                <div id="user-info-name">
&nbsp;                                              </div>
                                                <div id="user-info-username">
&nbsp;                                              </div>
                                                <div class="clearfix">
&nbsp;                                              </div>
                                            </div>
                                        </div>
                                        <div id="user-info-profile">
                                            <ul class="unstyled">
                                                <li id="MyDeveloperAcc">
                                                    <a>
My Developer Account >                                                  </a>
                                                </li>
                                                <li id="CreateNewAcc">
                                                    <a>
Create Account >                                                    </a>
                                                </li>
                                                <li id="MySettings">
                                                    <a>
My Settings >                                                   </a>
                                                </li>
                                            </ul>
                                        </div>
                                        <button id="user-info-logout" onclick="javascript:void(0);">
Log out                                     </button>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="social-search clearfix pull-right">
                            <div id="search-social-container" class="search-social-inner clearfix" data-placeholder="Search">
                                <gcse:searchbox-only resultsUrl="https://go.pardot.com/s/27572/bZmGraVP6uMckd2zJnklMehlfDezI7wZ" enableAutoComplete="true">
&nbsp;                              </gcse:searchbox-only>
                                <div id="login-logout2" class="login-logout hidden">
                                    <A id="sdn-login-link2" class="login-link" href="//org.developer.salesforce.com/forums/CommunitiesLogin?startURL=">
Login                                   </A>
                                    <ul class="nav nav-pills">
                                        <li class="dropdown">
                                            <a class="dropdown-toggle" data-toggle="dropdown" href="#link">
<img src="/resource/images/user-picture.jpg"/>                                          </a>
                                            <ul class="dropdown-menu">
                                                <li class="name">
                                                    <a href="#">
                                                        <span data-user-field="firstname">
&nbsp;                                                      </span>
                                                        <span data-user-field="lastname">
&nbsp;                                                      </span>
                                                    </a>
                                                </li>
                                                <li class="email" data-user-field="username">
&nbsp;                                              </li>
                                                <li class="divider">
&nbsp;                                              </li>
                                                <li class="logout">
                                                    <a href="#link">
Logout                                                  </a>
                                                </li>
                                            </ul>
                                        </li>
                                    </ul>
                                </div>
                            </div>
                        </div>
                        <div style="height: auto;" class="nav-collapse in collapse">
                            <ul id="nav-to-highlight-based-on-url2" class="nav primary-nav clearfix">
                                <li class="dropdown">
                                    <a data-toggle="dropdown" href="/platform/overview">
Products                                    </a>
                                    <ul class="dropdown-menu">
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/platform">
App Cloud                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/platform/force.com">
- Force.com                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/platform/heroku">
 - Heroku                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/lightning">
 - Lightning                                            </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/mobile">
 - Mobile                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com">
 - Trailhead                                            </a>
                                        </li>
                                                                                <li class="spaced-item">
                                            <a class="medium-link" href="/platform/dx">
 - Salesforce DX                                            </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/platform/appexchange">
 - AppExchange                                          </a>
                                        </li>
                                    </ul>
                                </li>
                                <li class="dropdown">
                                    <a data-toggle="dropdown" href="/resources">
Resources                                   </a>
                                    <ul class="dropdown-menu library">
                                        <li style="overflow:hidden;">
                                            <div style="width:265px;" class="pull-left span">
                                                <p>

    <em>Learn</em>
                                                </p>
                                                <ul style="width:50.0%;float:left;" class="unstyled">
                                                    <li class="spaced-item">
                                                        <A class="medium-link" href="/gettingstarted">
Getting Started                                                     </A>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/docs">
Documentation                                                       </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/blogs/developer-relations/2016/09/winter-17-highlights-developers.html">
Release Overview                                                        </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="https://trailhead.salesforce.com">
Trailhead                                                       </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Developer_Library">
Books &amp; Cheat Sheets                                                        </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/content/type/Webinar">
On-Demand Webinars                                                      </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="http://certification.salesforce.com/platform-developers" target="_blank">
Certification <i class="icon-external-link"></i>                                                        </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/blogs/">
Blogs                                                       </a>
                                                    </li>
                                                </ul>
                                            </div>
                                            <div style="width:244px;" class="pull-left span">
                                                <p>

    <em>Tools</em>
                                                </p>
                                                <ul style="width:50.0%;float:left;" class="unstyled">
                                                    <li class="spaced-item medium-link">
                                                        <a href="/page/Force.com_IDE">Force.com IDE</a>
                                                    </li>
                                                    <li class="spaced-item medium-link">
                                                        <a href="/tools/forcecli">Force.com CLI</a>
                                                    </li>
                                                    <li class="spaced-item medium-link">
                                                        <a href="https://www.lightningdesignsystem.com/" target="_blank">
Lightning Design System <i class="icon-external-link"></i>                                                      </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Security_Tools">
Source Code Scanner                                                     </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Tools">
More Tools &amp; Toolkits                                                       </a>
                                                    </li>
                                                </ul>
                                            </div>
                                            <div class="pull-left span">
                                                <p>

    <em>By Topic</em>
                                                </p>
                                                <ul style="width:50.0%;float:left;" class="unstyled">
                                                    <li class="spaced-item medium-link">
                                                        <a href="/page/App_Distribution">
App Distribution                                                        </a>
                                                    </li>
                                                    <li class="spaced-item medium-link">
                                                        <a href="/page/App_Logic">
App Logic                                                       </a>
                                                        <li class="spaced-item medium-link">
                                                            <a href="/page/Architect_Core_Resources">
Architect                                                           </a>
                                                        </li>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Database">
Database                                                        </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/devcenter/lightning">
Lightning                                                       </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/devcenter/mobile">
Mobile                                                      </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Integration">
Integration                                                     </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Security">
Security                                                        </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/UserInterface">
User Interface                                                      </a>
                                                    </li>
                                                    <li class="spaced-item">
                                                        <a class="medium-link" href="/page/Websites">
Websites                                                        </a>
                                                    </li>
                                                </ul>
                                            </div>
                                        </li>
                                    </ul>
                                </li>
                                <li class="dropdown">
                                    <a data-toggle="dropdown" href="//events.developerforce.com/signup?d=70130000000tgM8">
Community                                   </a>
                                    <ul class="dropdown-menu">
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/forums">
Developer Forums                                            </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/calendar">
Events Calendar                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/mvp">
Developer MVPs                                          </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="http://www.meetup.com/pro/salesforcedevs" target="_blank">
Developer Groups <i class="icon-external-link"></i>                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/success-stories">
Developer Success Stories                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs/">
Blogs                                           </a>
                                        </li>
                                    </ul>
                                </li>
                                <li class="dropdown">
                                    <a data-toggle="dropdown" href="//events.developerforce.com/signup?d=70130000000tgM8">
Blog                                    </a>
                                    <ul class="dropdown-menu">
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs">
All Blogs                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs/developer-relations/">
Developer Relations                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs/engineering">
Engineering                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs/labs">
Force.com Labs                                          </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="/blogs/tech-pubs">
Tech Docs                                           </a>
                                        </li>
                                    </ul>
                                </li>
                                <li class="dropdown">
                                    <a data-toggle="dropdown" href="https://trailhead.salesforce.com">
Trailhead                                   </a>
                                    <ul class="dropdown-menu">
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com">
Trailhead                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com/trails">
 - Trails                                           </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com/modules">
 - Modules                                          </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com/projects">
 - Projects                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com/super_badges">
 - Superbadges                                          </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://trailhead.salesforce.com/trailblazers">
 - Trailblazers                                         </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://developer.salesforce.com/forums?communityId=09aF00000004HMGIA2#!/feedtype=RECENT&amp;dc=Trailhead&amp;criteria=ALLQUESTIONS" target="_blank">
Get Help                                            </a>
                                        </li>
                                        <li class="spaced-item">
                                            <a class="medium-link" href="https://success.salesforce.com/_ui/core/chatter/groups/GroupProfilePage?g=0F9300000009Nek" target="_blank">
Join the Community <i class="icon-external-link"></i>                                           </a>
                                        </li>
                                    </ul>
                                </li>
                            </ul>
                        </div>
                    </div>
                    <div class="mobile mobileHeader">
                        <a id="mobileMenu">
<img src="/resource/images/MenuMobile.png"/>                        </a>
                        <a class="mobileLogo" href="/">
<img src="/resource/images/salesforce-developer-network-logo_1.png" class="sewg314" style="width:118px;"/>                      </a>
                        <a id="mobileSearch">
<img src="/resource/images/SearchMobile.png"/>                      </a>
                    </div>
                </div>
            </div>
        </div>
<script src="/resource/javascripts/afterheader.min.js"></script>

<script>
    function call_campaigns_cookie(){
        var params = document.location.search.substring(1);
        var utm_source = '';
        var utm_medium = '';
        var utm_campaign = '';
        var dr = '';
        params_array = params.split('&');
        for(i=0;i<params_array.length;i++){
            param_array = params_array[i].split('=');
            if(param_array[0]=='utm_source'){
                utm_source = param_array[1];
            }else if(param_array[0]=='utm_medium'){
                utm_medium = param_array[1];
            }else if(param_array[0]=='utm_campaign'){
                utm_campaign = param_array[1];
            }else if(param_array[0]=='dr'){
                dr = param_array[1];
            }
        }

        if(utm_source!=null && utm_source!='' && 
            utm_medium!=null && utm_medium!='' && 
            utm_campaign!=null && utm_campaign!=''){
            //do call
            $.get( "/events/campaigns_cookie", { utm_source: utm_source, utm_medium: utm_medium, utm_campaign: utm_campaign, dr: dr } );
        }
    }
    function animateSearchIn() {
        $('#mobileSearchContainerOverlay').fadeIn();
        $('#mobileSearchContainer').fadeIn();
        $('.gsc-input').focus();
        $("#mobileSearchContainer .searchBar").animate({
          top: '0px',
        }, 500, function() {
            
            $("#mobileSearchContainer .searchBar").animate({
              top: '-20px',
            }, 300);
            
        });
    }
    
    function animateSearchOut() {
        $("#mobileSearchContainer .searchBar").animate({
          top: '0px',
        }, 300, function() {
            $("#mobileSearchContainer .searchBar").animate({
              top: '-80px',
            }, 500, function() {
                $('#mobileSearchContainer').fadeOut();
                $('#mobileSearchContainerOverlay').fadeOut();
                $('.gsc-input').val('');
            });
        });
    }
    
    var intval_placeholder_search;
    
    function checkPlaceholderSearch(){
        if( jQuery("#newSearchContainer").find('input[name="search"]').length == 1 ){
            var a=jQuery("#newSearchContainer");
            a.find('input[name="search"]').attr("placeholder",a.attr("data-placeholder"));
            
            $('#newSearchContainer td.gsc-input').after($('<div class="clear-icon"></div>'));
        
            $('.clear-icon').click(function(){
                $('#newSearchContainer input.gsc-input').val('');
            });
            clearInterval(intval_placeholder_search);
        }
    }
    
    function makeNewSearch(){
      var newMobileSearchOverlay = $('<div></div>').attr('id', 'mobileSearchContainerOverlay');
      var newMobileSearch = $('<div></div>').attr('id', 'mobileSearchContainer');
      var searchBar = $('<div></div>').addClass('searchBar');
        
      var newSearchContainer = $('<div></div>').attr({
        id: 'newSearchContainer',
        'data-placeholder':'Search'
      });
        
      var newSearch = $('<gcse:searchbox-only></gcse:searchbox-only>').attr({
          resultsUrl : '//go.pardot.com/s/27572/bZmGraVP6uMckd2zJnklMehlfDezI7wZ',
          enableAutoComplete : true
      });
        
      $(newSearchContainer).append(newSearch);
      
      $(searchBar).append(newSearchContainer);
      $(newMobileSearch).append($(searchBar));
        
      $('body').prepend(newMobileSearchOverlay);
      $('body').prepend(newMobileSearch);
      
      $(newMobileSearchOverlay).click(function(){
          animateSearchOut();
      });
        
        
      if( jQuery("#newSearchContainer").find('input[name="search"]').length == 0 ){
          intval_placeholder_search = setInterval(function(){ checkPlaceholderSearch() }, 100);
      }
    }
    
    var intervalBtn;
    
    function placeMobileSearchCancelBtn(){
        if( $('#mobileSearchContainer td.gsc-clear-button').length > 0 ){
            
            clearInterval(intervalBtn);
            
            $('#mobileSearchContainer .gsc-search-button').remove();
        
            var cancelBtn = $('<button></button>');

            $(cancelBtn).text('Cancel').attr('type', 'button').click(function(){
                hideMobileSearchContainer();
            });
            
            
            
            $('#mobileSearchContainer div.gsc-clear-button').remove();
            $('#mobileSearchContainer td.gsc-clear-button').append(cancelBtn);
        }
    }

    function showMobileSearchContainer(){
        
        if( $('#mobileSearchContainer .gsc-clear-button button').length == 0 ){
            placeMobileSearchCancelBtn();
        }
        
        if( $('#mobileSearchContainer td.gsc-clear-button').length == 0 ){
            intervalBtn = setInterval(function(){placeMobileSearchCancelBtn()}, 500);
        }
        animateSearchIn();
        
    }
    
    function hideMobileSearchContainer(){
        animateSearchOut();
    }
    
    function mobileSidebarFix(){
        if( $('body').width() <= 979 ){
            $('.mobileHeaderContainer').addClass('on-mobile');
        }else{
            $('.mobileHeaderContainer').removeClass('on-mobile');
        }
    }
    
    var hideMobileHeaderContainer = true;


    $(document).ready(function(){
        
        /*!
        * jquery.scrollto.js 0.0.1 - https://github.com/yckart/jquery.scrollto.js
        * Scroll smooth to any element in your DOM.
        *
        * Copyright (c) 2012 Yannick Albert (http://yckart.com)
        * Licensed under the MIT license (http://www.opensource.org/licenses/mit-license.php).
        * 2013/02/17
        **/
        $.scrollTo = $.fn.scrollTo = function(x, y, options){
            if (!(this instanceof $)) return $.fn.scrollTo.apply($('html, body'), arguments);

            options = $.extend({}, {
                gap: {
                    x: 0,
                    y: 1
                },
                animation: {
                    easing: 'swing',
                    duration: 600,
                    complete: $.noop,
                    step: $.noop
                }
            }, options);

            return this.each(function(){
                var elem = $(this);
                elem.stop().animate({
                    scrollLeft: !isNaN(Number(x)) ? x : $(y).offset().left + options.gap.x,
                    scrollTop: !isNaN(Number(y)) ? y : $(y).offset().top + options.gap.y
                }, options.animation);
            });
        };
        
        makeNewSearch();
        mobileSidebarFix();
        
        $('#mobileSearch').unbind('click');
        
        $('#mobileSearch').click(function(){
          showMobileSearchContainer();
        });
        
        
        
        $(window).scroll(function() {
            
            if( hideMobileHeaderContainer == true && $(window).scrollLeft() > ($('.mobileHeaderContainer').outerWidth()/2) ){ 
                hideMobileHeaderContainer = false;
                
                setTimeout(function(){hideMobileHeaderContainer=true;}, 600);
                //$('html,body').scrollTo(0, 0, function(){});
                $('header').removeClass('showMobile');
                $('#SDNmaintemplate').removeClass('showMobile');
                $('footer').removeClass('showMobile');
            }
        });
        
        $(window).resize(function(){
            mobileSidebarFix();
        });
        call_campaigns_cookie();
    });
    
</script>

<link href='/resources2/stylesheets/dsc-header.css' rel='stylesheet' type='text/css'/>

<!--</dfc-header>-->
        </header><!--<dfc-nav>-->
<div id="navigation-bar">
  <div class="container">
      <div class="row">
          <div class="span9">
              <div>
          <div class="hidden <dfc-show-breadcrumb/>">
            <dfc-breadcumbs/>
          </div>
          <h1 class="<dfc-no-breadcrumb/>"><dfc-nav-title/></h1>
        </div>
          </div>
          <div class="span3">
              <div>
                  <div id="discussion_board_socialData">
                    <div id="forums_social_wrapper" class="forums_social_wrapper">
              <!-- Go to www.addthis.com/dashboard to customize your tools -->
                          <div class="addthis_custom_sharing"></div>
              <!-- AddThis Button END -->
              <div class="clear_both"></div>
            </div>
          </div>
        </div>
      </div>
      </div>
    </div>
</div>
<!--</dfc-nav>-->

            
            <div class="csMini">
                <div class="threecolumn">
                    <div class="leftContent">
                        <div><span id="j_id0:j_id1:j_id28">
    <div id="forums_login_wrapper"><span id="j_id0:j_id1:j_id28:j_id29:j_id43">
            <div class="forums_login_wrapper">
                <div class="reg-sign-up_div">
                    <div class="cloudImg"></div>
                    <div class="reg-sign-up_btn_div">
                        <button class="reg-sign-up" name="button" onclick="window.location.href='/forums/CommunitiesLogin?startURL=/forums'" type="submit">Login with Salesforce</button>
                    </div>
                </div>
                <div style="clear: both;"></div>
                <p class="dont_have_account">Don't have an account?</p>
                <a class="signup_dev_edition" href="/signup?d=70130000000tgM8">Signup for a Developer Edition</a>
            </div></span>
        <div style="clear:both"></div>
    </div></span>
                        </div>
                        <div class="caleftnavseparator"></div>
                        <div><span id="j_id0:j_id1:j_id47">
    
    <script>
  var categories_name = [];
   categories_name['Apex_Code_Development'] = 'Apex Code Development';
   categories_name['General_Development'] = 'General Development';
   categories_name['Visualforce_Development'] = 'Visualforce Development';
   categories_name['Formulas_Validation_Rules_Discussion'] = 'Formulas & Validation Rules Discussion';
   categories_name['APIs_and_Integration'] = 'APIs and Integration';
   categories_name['Jobs_Board'] = 'Jobs Board';
   categories_name['Other_Salesforce_Applications'] = 'Other Salesforce Applications';
   categories_name['Force_com_Sites_Site_com'] = 'Force.com Sites & Site.com';
   categories_name['Java_Development'] = 'Java Development';
   categories_name['Trailhead'] = 'Trailhead';
   categories_name['NET_Development'] = '.NET Development';
   categories_name['Perl_PHP_Python_Ruby_Development'] = 'Perl, PHP, Python & Ruby Development';
   categories_name['AppExchange_Directory_Packaging'] = 'AppExchange Directory & Packaging';
   categories_name['Mobile'] = 'Mobile';
   categories_name['Security'] = 'Security';
   categories_name['Lightning'] = 'Lightning';
   categories_name['Chatter_and_Chatter_API_Development'] = 'Chatter and Chatter API Development';
   categories_name['Visual_Workflow'] = 'Visual Workflow';
   categories_name['Salesforce_Labs_Open_Source_Projects'] = 'Salesforce Labs & Open Source Projects';
   categories_name['Desktop_Integration'] = 'Desktop Integration';
   categories_name['Apple_Mac_and_OS_X'] = 'Apple, Mac and OS X';
   categories_name['VB_and_Office_Development'] = 'VB and Office Development';
   categories_name['Schema_Development'] = 'Schema Development';
   categories_name['Architecture'] = 'Architecture';
   categories_name['General_JP'] = '一般 - General-JP';
   categories_name['App_Logic_JP'] = 'アプリケーションロジック - App Logic-JP';
   categories_name['User_Interface_JP'] = 'ユーザインタフェース - User Interface-JP';
   categories_name['Salesforce_Summer_of_Hacks'] = 'Salesforce Summer of Hacks';
   categories_name['Salesforce_1_Million_Hackathon'] = 'Salesforce $1 Million Hackathon';
   categories_name['Database_JP'] = 'データベース - Database-JP';
   categories_name['Integration_JP'] = 'インテグレーション - Integration-JP';
   categories_name['Web_Web_Sites_JP'] = 'Webサイト - Web Sites-JP';
   categories_name['App_Distribution_JP'] = 'アプリケーションの配布 - App Distribution-JP';
   categories_name['Mobile_JP'] = 'モバイル - Mobile-JP';
   categories_name['Announcements_JP'] = 'ご案内 - Announcements-JP';
   categories_name['Chatter_JP'] = 'ソーシャル - Chatter-JP';
   categories_name['Predictive_Services'] = 'Predictive Services';
 </script>
    
    <div class="datacategorylinks csoptimizequestion">
        <h3 id="ext-gen31" title="Filter questions and answers by topic">Browse by Topic</h3>
        <ul>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxApex_Code_Development" data-dc="Apex_Code_Development" href="/#!/feedtype=RECENT&amp;dc=Apex_Code_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Apex Code Development <span class="cacategorycounter">(56989)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxGeneral_Development" data-dc="General_Development" href="/#!/feedtype=RECENT&amp;dc=General_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />General Development <span class="cacategorycounter">(43016)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxVisualforce_Development" data-dc="Visualforce_Development" href="/#!/feedtype=RECENT&amp;dc=Visualforce_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Visualforce Development <span class="cacategorycounter">(29313)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxFormulas_Validation_Rules_Discussion" data-dc="Formulas_Validation_Rules_Discussion" href="/#!/feedtype=RECENT&amp;dc=Formulas_Validation_Rules_Discussion&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Formulas &amp; Validation Rules Discussion <span class="cacategorycounter">(7057)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxAPIs_and_Integration" data-dc="APIs_and_Integration" href="/#!/feedtype=RECENT&amp;dc=APIs_and_Integration&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />APIs and Integration <span class="cacategorycounter">(6845)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxJobs_Board" data-dc="Jobs_Board" href="/#!/feedtype=RECENT&amp;dc=Jobs_Board&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Jobs Board <span class="cacategorycounter">(6116)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxOther_Salesforce_Applications" data-dc="Other_Salesforce_Applications" href="/#!/feedtype=RECENT&amp;dc=Other_Salesforce_Applications&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Other Salesforce Applications <span class="cacategorycounter">(5632)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxForce_com_Sites_Site_com" data-dc="Force_com_Sites_Site_com" href="/#!/feedtype=RECENT&amp;dc=Force_com_Sites_Site_com&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Force.com Sites &amp; Site.com <span class="cacategorycounter">(3646)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxJava_Development" data-dc="Java_Development" href="/#!/feedtype=RECENT&amp;dc=Java_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Java Development <span class="cacategorycounter">(3523)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxTrailhead" data-dc="Trailhead" href="/#!/feedtype=RECENT&amp;dc=Trailhead&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Trailhead <span class="cacategorycounter">(3465)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxMobile" data-dc="Mobile" href="/#!/feedtype=RECENT&amp;dc=Mobile&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Mobile <span class="cacategorycounter">(1783)</span></a>
           </li>
           <li class="datacategoryoption csChildOption ">
               <a class="cxdatacategory cxLightning" data-dc="Lightning" href="/#!/feedtype=RECENT&amp;dc=Lightning&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Lightning <span class="cacategorycounter">(1743)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxNET_Development" data-dc="NET_Development" href="/#!/feedtype=RECENT&amp;dc=NET_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />.NET Development <span class="cacategorycounter">(3338)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxPerl_PHP_Python_Ruby_Development" data-dc="Perl_PHP_Python_Ruby_Development" href="/#!/feedtype=RECENT&amp;dc=Perl_PHP_Python_Ruby_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Perl, PHP, Python &amp; Ruby Development <span class="cacategorycounter">(1899)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxAppExchange_Directory_Packaging" data-dc="AppExchange_Directory_Packaging" href="/#!/feedtype=RECENT&amp;dc=AppExchange_Directory_Packaging&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />AppExchange Directory &amp; Packaging <span class="cacategorycounter">(1820)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxMobile" data-dc="Mobile" href="/#!/feedtype=RECENT&amp;dc=Mobile&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Mobile <span class="cacategorycounter">(1783)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxSecurity" data-dc="Security" href="/#!/feedtype=RECENT&amp;dc=Security&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Security <span class="cacategorycounter">(1769)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxLightning" data-dc="Lightning" href="/#!/feedtype=RECENT&amp;dc=Lightning&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Lightning <span class="cacategorycounter">(1743)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxChatter_and_Chatter_API_Development" data-dc="Chatter_and_Chatter_API_Development" href="/#!/feedtype=RECENT&amp;dc=Chatter_and_Chatter_API_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Chatter and Chatter API Development <span class="cacategorycounter">(1446)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxVisual_Workflow" data-dc="Visual_Workflow" href="/#!/feedtype=RECENT&amp;dc=Visual_Workflow&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Visual Workflow <span class="cacategorycounter">(1125)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxSalesforce_Labs_Open_Source_Projects" data-dc="Salesforce_Labs_Open_Source_Projects" href="/#!/feedtype=RECENT&amp;dc=Salesforce_Labs_Open_Source_Projects&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Salesforce Labs &amp; Open Source Projects <span class="cacategorycounter">(1015)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxDesktop_Integration" data-dc="Desktop_Integration" href="/#!/feedtype=RECENT&amp;dc=Desktop_Integration&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Desktop Integration <span class="cacategorycounter">(975)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxApple_Mac_and_OS_X" data-dc="Apple_Mac_and_OS_X" href="/#!/feedtype=RECENT&amp;dc=Apple_Mac_and_OS_X&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Apple, Mac and OS X <span class="cacategorycounter">(712)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxVB_and_Office_Development" data-dc="VB_and_Office_Development" href="/#!/feedtype=RECENT&amp;dc=VB_and_Office_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />VB and Office Development <span class="cacategorycounter">(613)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxSchema_Development" data-dc="Schema_Development" href="/#!/feedtype=RECENT&amp;dc=Schema_Development&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Schema Development <span class="cacategorycounter">(612)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxArchitecture" data-dc="Architecture" href="/#!/feedtype=RECENT&amp;dc=Architecture&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Architecture <span class="cacategorycounter">(443)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxSalesforce_Summer_of_Hacks" data-dc="Salesforce_Summer_of_Hacks" href="/#!/feedtype=RECENT&amp;dc=Salesforce_Summer_of_Hacks&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Salesforce Summer of Hacks <span class="cacategorycounter">(133)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxSalesforce_1_Million_Hackathon" data-dc="Salesforce_1_Million_Hackathon" href="/#!/feedtype=RECENT&amp;dc=Salesforce_1_Million_Hackathon&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Salesforce $1 Million Hackathon <span class="cacategorycounter">(129)</span></a>
           </li>
           <li class="datacategoryoption csChildOption " style="display:none">
               <a class="cxdatacategory cxPredictive_Services" data-dc="Predictive_Services" href="/#!/feedtype=RECENT&amp;dc=Predictive_Services&amp;criteria=ALLQUESTIONS"><img src="/s.gif" />Predictive Services <span class="cacategorycounter">(2)</span></a>
           </li>
        </ul>
        <ul>
            <li><a href="/forums/ForumsCategories" class="cacategoymorelink">View More Topics</a>
            </li>
            <li><a href="/forums/#!/feedtype=RECENT&criteria=ALLQUESTIONS" class="cacategoymorelink">See All Posts</a>
            </li>
        </ul>
    </div>
        <script>chatterService.initDatacategoryEvent();</script></span>
                        </div>
                        <div class="caleftnavseparator"></div>
                        
                    </div>
                    <div class="mainContent">
                        <div class="lowerMainContent" id="lowerMainContent">
                            <div class="centerContent" id="centerContent">
                                <div id="searchQuestion" style="display:none"><span id="j_id0:j_id1:j_id73"><script>if (!window.sfdcPage) {window.sfdcPage = new GenericSfdcPage();
UserContext.initialize({"ampm":["AM","PM"],"isAccessibleMode":false,"uiSkin":"Theme3","salesforceURL":"https://dfc-org-production.force.com?refURL=http%3A%2F%2Fdfc-org-production.force.com%2Fforums%2F","dateFormat":"M/d/yyyy","language":"en_US","locale":"en_US","userName":"salesforce_developer_community@dfc-org-production.force.com","userId":"005F0000003BGxZ","isCurrentlySysAdminSU":false,"renderMode":"RETRO","startOfWeek":"1","vfDomainPattern":"(?:[^.]+)*.na43.visual.force.com","auraDomain":"na43.lightning.force.com","dateTimeFormat":"M/d/yyyy h:mm a","orgPreferences":[{"index":257,"name":"TabOrganizer","value":true},{"index":113,"name":"GroupTasks","value":true}],"siteUrlPrefix":"/forums","isDefaultNetwork":false,"labelLastModified":"1479844900000","today":"11/26/2016 4:58 PM","timeFormat":"h:mm a","userPreferences":[{"index":112,"name":"HideInlineEditSplash","value":false},{"index":114,"name":"OverrideTaskSendNotification","value":false},{"index":115,"name":"DefaultTaskSendNotification","value":false},{"index":119,"name":"HideUserLayoutStdFieldInfo","value":false},{"index":116,"name":"HideRPPWarning","value":false},{"index":87,"name":"HideInlineSchedulingSplash","value":false},{"index":88,"name":"HideCRUCNotification","value":false},{"index":89,"name":"HideNewPLESplash","value":false},{"index":90,"name":"HideNewPLEWarnIE6","value":false},{"index":122,"name":"HideOverrideSharingMessage","value":false},{"index":91,"name":"HideProfileILEWarn","value":false},{"index":93,"name":"HideProfileElvVideo","value":false},{"index":97,"name":"ShowPicklistEditSplash","value":false},{"index":92,"name":"HideDataCategorySplash","value":false},{"index":128,"name":"ShowDealView","value":false},{"index":129,"name":"HideDealViewGuidedTour","value":false},{"index":132,"name":"HideKnowledgeFirstTimeSetupMsg","value":false},{"index":104,"name":"DefaultOffEntityPermsMsg","value":false},{"index":135,"name":"HideNewCsnSplash","value":false},{"index":101,"name":"HideBrowserWarning","value":false},{"index":139,"name":"HideDashboardBuilderGuidedTour","value":false},{"index":140,"name":"HideSchedulingGuidedTour","value":false},{"index":180,"name":"HideReportBuilderGuidedTour","value":false},{"index":183,"name":"HideAssociationQueueCallout","value":false},{"index":194,"name":"HideQTEBanner","value":false},{"index":193,"name":"HideChatterOnboardingSplash","value":false},{"index":195,"name":"HideSecondChatterOnboardingSplash","value":false},{"index":270,"name":"HideIDEGuidedTour","value":false},{"index":282,"name":"HideQueryToolGuidedTour","value":false},{"index":196,"name":"HideCSIGuidedTour","value":false},{"index":271,"name":"HideFewmetGuidedTour","value":false},{"index":272,"name":"HideEditorGuidedTour","value":false},{"index":205,"name":"HideApexTestGuidedTour","value":false},{"index":206,"name":"HideSetupProfileHeaderTour","value":false},{"index":207,"name":"HideSetupProfileObjectsAndTabsTour","value":false},{"index":213,"name":"DefaultOffArticleTypeEntityPermMsg","value":false},{"index":214,"name":"HideSelfInfluenceGetStarted","value":false},{"index":215,"name":"HideOtherInfluenceGetStarted","value":false},{"index":216,"name":"HideFeedToggleGuidedTour","value":false},{"index":268,"name":"ShowChatterTab178GuidedTour","value":false},{"index":275,"name":"HidePeopleTabDeprecationMsg","value":false},{"index":276,"name":"HideGroupTabDeprecationMsg","value":false},{"index":224,"name":"HideUnifiedSearchGuidedTour","value":false},{"index":226,"name":"ShowDevContextMenu","value":true},{"index":227,"name":"HideWhatRecommenderForActivityQueues","value":false},{"index":228,"name":"HideLiveAgentFirstTimeSetupMsg","value":false},{"index":232,"name":"HideGroupAllowsGuestsMsgOnMemberWidget","value":false},{"index":233,"name":"HideGroupAllowsGuestsMsg","value":false},{"index":234,"name":"HideWhatAreGuestsMsg","value":false},{"index":235,"name":"HideNowAllowGuestsMsg","value":false},{"index":236,"name":"HideSocialAccountsAndContactsGuidedTour","value":false},{"index":237,"name":"HideAnalyticsHomeGuidedTour","value":false},{"index":238,"name":"ShowQuickCreateGuidedTour","value":false},{"index":245,"name":"HideFilePageGuidedTour","value":false},{"index":250,"name":"HideForecastingGuidedTour","value":false},{"index":251,"name":"HideBucketFieldGuide","value":false},{"index":263,"name":"HideSmartSearchCallOut","value":false},{"index":265,"name":"HideSocialProfilesKloutSplashScreen","value":false},{"index":273,"name":"ShowForecastingQuotaAttainment","value":false},{"index":280,"name":"HideForecastingQuotaColumn","value":false},{"index":301,"name":"HideManyWhoGuidedTour","value":false},{"index":284,"name":"HideExternalSharingModelGuidedTour","value":false},{"index":298,"name":"HideFileSyncBannerMsg","value":false},{"index":299,"name":"HideTestConsoleGuidedTour","value":false},{"index":302,"name":"HideManyWhoInlineEditTip","value":false},{"index":303,"name":"HideSetupV2WelcomeMessage","value":false},{"index":312,"name":"ForecastingShowQuantity","value":false},{"index":313,"name":"HideDataImporterIntroMsg","value":false},{"index":314,"name":"HideEnvironmentHubLightbox","value":false},{"index":316,"name":"HideSetupV2GuidedTour","value":false},{"index":317,"name":"HideFileSyncMobileDownloadDialog","value":false},{"index":322,"name":"HideEnhancedProfileHelpBubble","value":false},{"index":328,"name":"ForecastingHideZeroRows","value":false},{"index":330,"name":"HideEmbeddedComponentsFeatureCallout","value":false},{"index":341,"name":"HideDedupeMatchResultCallout","value":false},{"index":340,"name":"HideS1BrowserUI","value":true},{"index":346,"name":"HideS1Banner","value":false},{"index":358,"name":"HideEmailVerificationAlert","value":false},{"index":354,"name":"HideLearningPathModal","value":false},{"index":359,"name":"HideAtMentionsHelpBubble","value":false},{"index":368,"name":"LightningExperiencePreferred","value":false}],"networkId":"0DBF0000000PAtV"});
}</script><script>chatterService.getToolbox().setIsGuestUser(true);</script><script>chatterService.getToolbox().setDataServletUrl('/forums/_ui/chatter/service/setup/ChatterServicePersonalSetup');</script><div id="auraElement-1"></div><div id="auraErrorMessage"></div>        <link href="/forums/l/%7B%22mode%22%3A%22PROD%22%2C%22app%22%3A%22serviceCommunity%3AserviceCommunityIntegrationApp%22%2C%22fwuid%22%3A%22TP0eb7RDpz6MQZsvYldHEg%22%2C%22loaded%22%3A%7B%22APPLICATION%40markup%3A%2F%2FserviceCommunity%3AserviceCommunityIntegrationApp%22%3A%22VpzVZrH5IXo-SFDgn6PEIA%22%7D%2C%22styleContext%22%3A%7B%22c%22%3A%22webkit%22%2C%22x%22%3A%5B%22isDesktop%22%5D%7D%2C%22ls%22%3A%22YN%22%7D/app.css" rel="stylesheet" type="text/css"/>
<style></style>       <script src="/forums/auraFW/resources/TP0eb7RDpz6MQZsvYldHEg/libs_GMT.js"></script>
       <script src="/forums/l/%7B%22mode%22%3A%22PROD%22%2C%22app%22%3A%22serviceCommunity%3AserviceCommunityIntegrationApp%22%2C%22fwuid%22%3A%22TP0eb7RDpz6MQZsvYldHEg%22%2C%22loaded%22%3A%7B%22APPLICATION%40markup%3A%2F%2FserviceCommunity%3AserviceCommunityIntegrationApp%22%3A%22VpzVZrH5IXo-SFDgn6PEIA%22%7D%2C%22ls%22%3A%22YN%22%7D/app.encryptionkey.js?jwt=45e60a6267582b79cf70c3ea3d0ecf86a32212780e7de0e14eff9b99aabe2aaf"></script>
       <script src="/forums/auraFW/javascript/TP0eb7RDpz6MQZsvYldHEg/aura_prod.js"></script>
       <script src="/forums/l/%7B%22mode%22%3A%22PROD%22%2C%22app%22%3A%22serviceCommunity%3AserviceCommunityIntegrationApp%22%2C%22fwuid%22%3A%22TP0eb7RDpz6MQZsvYldHEg%22%2C%22loaded%22%3A%7B%22APPLICATION%40markup%3A%2F%2FserviceCommunity%3AserviceCommunityIntegrationApp%22%3A%22VpzVZrH5IXo-SFDgn6PEIA%22%7D%2C%22ls%22%3A%22YN%22%7D/resources.js?version=1469064557000"></script>
       <script src="/forums/l/%7B%22mode%22%3A%22PROD%22%2C%22app%22%3A%22serviceCommunity%3AserviceCommunityIntegrationApp%22%2C%22fwuid%22%3A%22TP0eb7RDpz6MQZsvYldHEg%22%2C%22loaded%22%3A%7B%22APPLICATION%40markup%3A%2F%2FserviceCommunity%3AserviceCommunityIntegrationApp%22%3A%22VpzVZrH5IXo-SFDgn6PEIA%22%7D%2C%22ls%22%3A%22YN%22%7D/app.js"></script>
       <script src="/forums/l/%7B%22mode%22%3A%22PROD%22%2C%22app%22%3A%22serviceCommunity%3AserviceCommunityIntegrationApp%22%2C%22fwuid%22%3A%22TP0eb7RDpz6MQZsvYldHEg%22%2C%22loaded%22%3A%7B%22APPLICATION%40markup%3A%2F%2FserviceCommunity%3AserviceCommunityIntegrationApp%22%3A%22VpzVZrH5IXo-SFDgn6PEIA%22%7D%2C%22ls%22%3A%22YN%22%7D/bootstrap.js"></script>
<script>
    $A.initConfig({"instance":{"s":1,"v":{"componentDef":{"descriptor":"markup://serviceCommunity:serviceCommunityIntegrationApp"},"creationPath":"/*[0]"}},"ns":{"privileged":[],"internal":["FSC","FSCWavePU","FSCWave_preprod","FSCWave_uat","FSCWavepkg","FSC_CB","FSC_INS","FSC_RB","FSC_WM","FinServ","FinServWaveExt","FinServ_CB","FinServ_CB_Pre","FinServ_CB_SB","FinServ_INS","FinServ_INS_Pre","FinServ_INS_SB","FinServ_Pre","FinServ_RB","FinServ_RB_Pre","FinServ_RB_SB","FinServ_SB","FinServ_WM","FinServ_WM_Pre","FinServ_WM_SB","HC1","HC2","HC3","HC3a","HC4","HC4a","HC5","HealthCloud","HealthCloudGA","HealthCloudTest","HealthCloud_GA","HealthCloud_Pre","HealthCloud_SB","Health_Cloud_GA","adminui","aloha_sales_forecasting","aloha_sales_opptysplit","aloha_sales_tm2","analytics","analyticsHome","apex","appexUi","appexUiDev","assistantFramework","assistantFrameworkModules","aura","auraScl","auraStorage","auradev","auradocs","aurajstest","auraplat","builder_platform_process","calendar","clients","commerce","communitySetup","console","cooper","cordaDashboards","dashboards","dataImporter","ddcProspector","desktopDashboards","emailStream","emailui","embeddedService","environmenthub","et4ae5","externalServicesSetup","flexipage","flexipageEditor","flowruntime","force","forceChatter","forceCommunity","forceContent","forceKnowledge","forceLicensing","forceSearch","forceTopic","fsc1_r1","fsc2_r1","fsc3_r1","fscwealth","fscwealthE","fscwealthfuture","fscwealthpatch","fscwmmain","googleConnector","hammerSetup","hc1_r1","hc2_r1","hc3_r1","health_cloud","healthblitz","healthfuture","healthmain","healthone","healthpatch","healthtest","home","instrumentation","kbmanagement","knowledgeone","lcwizard","lightning","liveAgent","ltng","ltngdoc","ltngtools","ltngx","macros","mcdm","mcdm_1","mcdm_10","mcdm_2","mcdm_3","mcdm_4","mcdm_5","mcdm_6","mcdm_7","mcdm_8","mcdm_9","mobile","myday","native","notes","objectManager","offline","omni","onboarding","onboardingTest","one","onesetup","opencti","packagingSetupUI","platformencryption","processui","processuiappr","processuicommon","processuimgnt","processuirule","processuitest","reports","runtime_industries_survey","runtime_ladybug","runtime_platform_testhistory","runtime_platformservices_transactionSecurity","runtime_sales_activities","runtime_sales_campaign","runtime_sales_commerce","runtime_sales_forecasting","runtime_sales_lead","runtime_sales_merge","runtime_sales_pathassistant","runtime_sales_pipelineboard","runtime_sales_quotes","runtime_sales_skype","runtime_sales_social","runtime_sales_xclean","s1wizard","salesforceIdentity","securityHealth","securitycentral","selfService","serviceCommunity","setup","setupAssistant","setup_lightning_visualforce","setup_platform_cloudconsole","setup_platformservices_customplatform","setup_sales_leadiq","setup_sales_pathassistant","setup_service","setupnav","setupwizard","sfa","siteforce","siteforceBuilder","socialService","support","templatesetup","today","ui","uiExamples","uns","userProvisioningUI","visualEditor","voice","wave","wealthone","wealthoneblitz","wealthonep","wits","work","workAloha"]},"host":"/forums","context":{"mode":"PROD","app":"serviceCommunity:serviceCommunityIntegrationApp","contextPath":"/forums","fwuid":"TP0eb7RDpz6MQZsvYldHEg","loaded":{"APPLICATION@markup://serviceCommunity:serviceCommunityIntegrationApp":"VpzVZrH5IXo-SFDgn6PEIA"},"globalValueProviders":[{"type":"$SObjectType","values":{"CurrentUser":{"isChatterEnabled":false}}},{"type":"$Mail","values":{"areAssociationPermsEnabled":true,"isSaveAttachmentEnabled":true,"isCustomizable":false,"killerUX":true}},{"type":"$Locale","values":{"userLocaleLang":"en","userLocaleCountry":"US","language":"en","country":"US","variant":"","langLocale":"en_US","nameOfMonths":[{"fullName":"January","shortName":"Jan"},{"fullName":"February","shortName":"Feb"},{"fullName":"March","shortName":"Mar"},{"fullName":"April","shortName":"Apr"},{"fullName":"May","shortName":"May"},{"fullName":"June","shortName":"Jun"},{"fullName":"July","shortName":"Jul"},{"fullName":"August","shortName":"Aug"},{"fullName":"September","shortName":"Sep"},{"fullName":"October","shortName":"Oct"},{"fullName":"November","shortName":"Nov"},{"fullName":"December","shortName":"Dec"},{"fullName":"","shortName":""}],"nameOfWeekdays":[{"fullName":"Sunday","shortName":"SUN"},{"fullName":"Monday","shortName":"MON"},{"fullName":"Tuesday","shortName":"TUE"},{"fullName":"Wednesday","shortName":"WED"},{"fullName":"Thursday","shortName":"THU"},{"fullName":"Friday","shortName":"FRI"},{"fullName":"Saturday","shortName":"SAT"}],"labelForToday":"Today","firstDayOfWeek":1,"dateFormat":"MMM d, yyyy","datetimeFormat":"MMM d, yyyy h:mm:ss a","timeFormat":"h:mm:ss a","timezone":"GMT","timezoneFileName":"GMT","isEasternNameStyle":false,"numberFormat":"#,##0.###","decimal":".","grouping":",","zero":"0","percentFormat":"#,##0%","currencyFormat":"¤#,##0.00","currencyCode":"USD","currency":"$"}},{"type":"$Browser","values":{"containerVersion":"","isWEBKIT":true,"isIE11":false,"formFactor":"DESKTOP","isIE10":false,"isContainer":false,"isBlackBerry":false,"isIE7":false,"isIE6":false,"isIE9":false,"isIE8":false,"isDesktop":true,"isTablet":false,"isIPad":false,"isWindowsTablet":false,"isPhone":false,"S1Features":{"useNativeScroller":false,"isAsyncSaveEnabled":false,"isEncryptedStorageEnabled":true,"isSFXUrlFormatSupported":false,"isAuraParallelBootstrapLoadEnabled":true,"isSocialInsightsLogoAdmin":false,"isSFXInlineEditListViewEnabled":true,"areOfflineDraftsEnabled":false,"isEclairAdvancedFeaturesEnabled":false,"isAccountSuggestionsEnabled":false,"isAccountLogoEnabled":false,"isUitrkLoggingEnabled":true,"isTodayPreviewEnabled":false,"isOfflineEnabled":true},"isFIREFOX":false,"isWindowsPhone":false,"isOSX":false,"isAndroid":false,"isIPhone":false,"isIOS":false}},{"type":"$SfdcSite","values":{"pathPrefix":"/forums"}},{"type":"$Global","values":{"isVoiceOver":{"writable":true,"defaultValue":false},"appContextId":{"writable":true,"defaultValue":""},"dynamicTypeSize":{"writable":true,"defaultValue":""}}}],"enableAccessChecks":true}}, true, true, true);
    </script><script>$A.__aisScopedCallback(function() { $A.clientService.injectComponentAsync({'componentDef': 'markup://serviceCommunity:searchAskWidgetMain', 'attributes': { 'values' : {"searchAskState":0,"zoneId":"09aF00000004HMGIA2","guestUser":true,"noSignIn":true} }, 'localId': '1'}, 'auraElement-1', undefined); });</script><div id="cs:supportBubble" class="prompt" style="display:none;">
    <h3>Welcome to Support!</h3>
    <p>Search for an answer or ask a question of the zone or Customer Support.</p>
    <a href="javascript:openPopupFocusEscapePounds(%27https://dfc-org-production.force.com/forums/ChatterAnswersHelp%27, %27Help%27, 1024, 768, %27width=1024,height=768,resizable=yes,toolbar=yes,status=yes,scrollbars=yes,menubar=yes,directories=no,location=yes,dependant=no%27, false, false);" class="faqLink">Need help?</a>
    <a href="javascript:void(0);" onclick="chatterService.hideHelpWidget();" class="dismiss">Dismiss</a>
    <span class="csTip" title=""></span>
</div>
<script>Ext.fly(window).on('load', function() {if ((window.sfdcPage) && (sfdcPage.executeOnloadQueue)){sfdcPage.executeOnloadQueue();};chatterService.initSearchAsk({isTBEnabled:true,isRTEnabled:true,inPortal:false,isNewAuraPublisher:true,communityId:'09aF00000004HMGIA2',loginPageUrl:'https://dfc-org-production.force.com/forums/ChatterAnswersLogin'});});chatterService.getToolbox().setNoSignIn('true');chatterService.getToolbox().setLanguage('en_US');</script></span>
                                </div>
                                <div class="hidden" id="login_prompt_search">
                                    <p>You need to sign in to do that</p>
                                    <p><a href="/forums/CommunitiesLogin?startURL=/forums">Sign in to start searching questions</a></p>
                                    <br />
                                    <p>Don't have an account?</p>
                                    <p><a href="/signup?d=70130000000tgM8">Signup for a Developer Edition</a></p>
                                </div>
                                <div><span id="j_id0:j_id1:j_id77"><script>if (!window.sfdcPage) {window.sfdcPage = new GenericSfdcPage();
UserContext.initialize({"ampm":["AM","PM"],"isAccessibleMode":false,"uiSkin":"Theme3","salesforceURL":"https://dfc-org-production.force.com?refURL=http%3A%2F%2Fdfc-org-production.force.com%2Fforums%2F","dateFormat":"M/d/yyyy","language":"en_US","locale":"en_US","userName":"salesforce_developer_community@dfc-org-production.force.com","userId":"005F0000003BGxZ","isCurrentlySysAdminSU":false,"renderMode":"RETRO","startOfWeek":"1","vfDomainPattern":"(?:[^.]+)*.na43.visual.force.com","auraDomain":"na43.lightning.force.com","dateTimeFormat":"M/d/yyyy h:mm a","orgPreferences":[{"index":257,"name":"TabOrganizer","value":true},{"index":113,"name":"GroupTasks","value":true}],"siteUrlPrefix":"/forums","isDefaultNetwork":false,"labelLastModified":"1479844900000","today":"11/26/2016 4:58 PM","timeFormat":"h:mm a","userPreferences":[{"index":112,"name":"HideInlineEditSplash","value":false},{"index":114,"name":"OverrideTaskSendNotification","value":false},{"index":115,"name":"DefaultTaskSendNotification","value":false},{"index":119,"name":"HideUserLayoutStdFieldInfo","value":false},{"index":116,"name":"HideRPPWarning","value":false},{"index":87,"name":"HideInlineSchedulingSplash","value":false},{"index":88,"name":"HideCRUCNotification","value":false},{"index":89,"name":"HideNewPLESplash","value":false},{"index":90,"name":"HideNewPLEWarnIE6","value":false},{"index":122,"name":"HideOverrideSharingMessage","value":false},{"index":91,"name":"HideProfileILEWarn","value":false},{"index":93,"name":"HideProfileElvVideo","value":false},{"index":97,"name":"ShowPicklistEditSplash","value":false},{"index":92,"name":"HideDataCategorySplash","value":false},{"index":128,"name":"ShowDealView","value":false},{"index":129,"name":"HideDealViewGuidedTour","value":false},{"index":132,"name":"HideKnowledgeFirstTimeSetupMsg","value":false},{"index":104,"name":"DefaultOffEntityPermsMsg","value":false},{"index":135,"name":"HideNewCsnSplash","value":false},{"index":101,"name":"HideBrowserWarning","value":false},{"index":139,"name":"HideDashboardBuilderGuidedTour","value":false},{"index":140,"name":"HideSchedulingGuidedTour","value":false},{"index":180,"name":"HideReportBuilderGuidedTour","value":false},{"index":183,"name":"HideAssociationQueueCallout","value":false},{"index":194,"name":"HideQTEBanner","value":false},{"index":193,"name":"HideChatterOnboardingSplash","value":false},{"index":195,"name":"HideSecondChatterOnboardingSplash","value":false},{"index":270,"name":"HideIDEGuidedTour","value":false},{"index":282,"name":"HideQueryToolGuidedTour","value":false},{"index":196,"name":"HideCSIGuidedTour","value":false},{"index":271,"name":"HideFewmetGuidedTour","value":false},{"index":272,"name":"HideEditorGuidedTour","value":false},{"index":205,"name":"HideApexTestGuidedTour","value":false},{"index":206,"name":"HideSetupProfileHeaderTour","value":false},{"index":207,"name":"HideSetupProfileObjectsAndTabsTour","value":false},{"index":213,"name":"DefaultOffArticleTypeEntityPermMsg","value":false},{"index":214,"name":"HideSelfInfluenceGetStarted","value":false},{"index":215,"name":"HideOtherInfluenceGetStarted","value":false},{"index":216,"name":"HideFeedToggleGuidedTour","value":false},{"index":268,"name":"ShowChatterTab178GuidedTour","value":false},{"index":275,"name":"HidePeopleTabDeprecationMsg","value":false},{"index":276,"name":"HideGroupTabDeprecationMsg","value":false},{"index":224,"name":"HideUnifiedSearchGuidedTour","value":false},{"index":226,"name":"ShowDevContextMenu","value":true},{"index":227,"name":"HideWhatRecommenderForActivityQueues","value":false},{"index":228,"name":"HideLiveAgentFirstTimeSetupMsg","value":false},{"index":232,"name":"HideGroupAllowsGuestsMsgOnMemberWidget","value":false},{"index":233,"name":"HideGroupAllowsGuestsMsg","value":false},{"index":234,"name":"HideWhatAreGuestsMsg","value":false},{"index":235,"name":"HideNowAllowGuestsMsg","value":false},{"index":236,"name":"HideSocialAccountsAndContactsGuidedTour","value":false},{"index":237,"name":"HideAnalyticsHomeGuidedTour","value":false},{"index":238,"name":"ShowQuickCreateGuidedTour","value":false},{"index":245,"name":"HideFilePageGuidedTour","value":false},{"index":250,"name":"HideForecastingGuidedTour","value":false},{"index":251,"name":"HideBucketFieldGuide","value":false},{"index":263,"name":"HideSmartSearchCallOut","value":false},{"index":265,"name":"HideSocialProfilesKloutSplashScreen","value":false},{"index":273,"name":"ShowForecastingQuotaAttainment","value":false},{"index":280,"name":"HideForecastingQuotaColumn","value":false},{"index":301,"name":"HideManyWhoGuidedTour","value":false},{"index":284,"name":"HideExternalSharingModelGuidedTour","value":false},{"index":298,"name":"HideFileSyncBannerMsg","value":false},{"index":299,"name":"HideTestConsoleGuidedTour","value":false},{"index":302,"name":"HideManyWhoInlineEditTip","value":false},{"index":303,"name":"HideSetupV2WelcomeMessage","value":false},{"index":312,"name":"ForecastingShowQuantity","value":false},{"index":313,"name":"HideDataImporterIntroMsg","value":false},{"index":314,"name":"HideEnvironmentHubLightbox","value":false},{"index":316,"name":"HideSetupV2GuidedTour","value":false},{"index":317,"name":"HideFileSyncMobileDownloadDialog","value":false},{"index":322,"name":"HideEnhancedProfileHelpBubble","value":false},{"index":328,"name":"ForecastingHideZeroRows","value":false},{"index":330,"name":"HideEmbeddedComponentsFeatureCallout","value":false},{"index":341,"name":"HideDedupeMatchResultCallout","value":false},{"index":340,"name":"HideS1BrowserUI","value":true},{"index":346,"name":"HideS1Banner","value":false},{"index":358,"name":"HideEmailVerificationAlert","value":false},{"index":354,"name":"HideLearningPathModal","value":false},{"index":359,"name":"HideAtMentionsHelpBubble","value":false},{"index":368,"name":"LightningExperiencePreferred","value":false}],"networkId":"0DBF0000000PAtV"});
}</script><script>chatterService.getToolbox().setIsGuestUser(true);</script><script>chatterService.getToolbox().setDataServletUrl('/forums/_ui/chatter/service/setup/ChatterServicePersonalSetup');</script><div class="feedfiltersupermenu cafiltersupermenu zen"><div class="zen-select " data-sfdc-widget="SfdcCmp.Ui.Dropdown" role="application" 

        data-expandMode="click"

        data-autoFocus="true"
        
        data-autocollapse="true"
>


      <a id="feedFilterDropDownElement" class="zen-trigger " onclick="" href="javascript:void(0);" title="" aria-haspopup="true">
<span id="filterByTriggerText">Show</span><span id="filterDisplay" title="Show all questions in the zone as well as articles, if articles are enabled for your organization.">All Questions</span><span id="sortByTriggerText">sorted by</span><span id="sortDisplay" title="Show questions in order of the date they were asked.">Date Posted</span><span class="zen-selectArrow"></span>      </a>
        <div class="zen-options " role="menu" aria-labelledby="feedFilterDropDownElement">
<span class="facet facetheader filterHeader"><h4>Show</h4></span><span class="zen-optgroup combomenu-filter" data-sfdc-widget="SfdcCmp.Ui.OptGroup" role="radiogroup"><ul class="feedfilters"><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="#" class="cxcriteria cxALLQUESTIONS" data-criteria="ALLQUESTIONS" role="menuitemradio" title="Show all questions in the zone as well as articles, if articles are enabled for your organization.">All Questions</a></li><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="#" class="cxcriteria cxUNANSWERED" data-criteria="UNANSWERED" role="menuitemradio" title="Show all questions that don&#39;t have replies.">Unanswered Questions</a></li><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="#" class="cxcriteria cxOPENQUESTIONS" data-criteria="OPENQUESTIONS" role="menuitemradio" title="Show all questions that don&#39;t have a best answer.">Unsolved Questions</a></li><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="#" class="cxcriteria cxBESTANSWERS" data-criteria="BESTANSWERS" role="menuitemradio" title="Show all questions that have a best answer as well as articles, if articles are enabled for your organization.">Solved Questions</a></li></ul>
</span><span class="facet facetheader sortByHeader"><h4>sorted by</h4></span><span class="zen-optgroup combomenu-filter" data-sfdc-widget="SfdcCmp.Ui.OptGroup" role="radiogroup"><ul class="feedsortby"><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="?feedtype=RECENT" class="cxfeedtype cxRECENT" data-feedtype="RECENT" role="menuitemradio" title="Show questions in order of the date they were asked.">Date Posted</a></li><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="?feedtype=RECENT_REPLY" class="cxfeedtype cxRECENT_REPLY" data-feedtype="RECENT_REPLY" role="menuitemradio" title="Show questions that are new or have new comments first.">Recent Activity</a></li><li data-sfdc-widget="SfdcCmp.Ui.Option"><span class="zen-visualization"></span><a href="?feedtype=POPULAR" class="cxfeedtype cxPOPULAR" data-feedtype="POPULAR" role="menuitemradio" title="Show questions with the highest number of upvotes, followers, and likes first.">Most Popular</a></li></ul>
</span>     </div>
</div>
</div><script>Sfdc.onReady(function(){chatterService.initFeedFilterEvent();});</script></span>
                                </div>
                                    <div class="user_stats start_button" id="discussion_button">+ Start a Discussion</div>
                                    <div class="hidden" id="login_prompt_button">
                                        <p>You need to sign in to do that</p>
                                        <p><a href="/forums/CommunitiesLogin?startURL=/forums">Sign in to start a discussion</a></p>
                                        <br />
                                        <p>Don't have an account?</p>
                                        <p><a href="/signup?d=70130000000tgM8">Signup for a Developer Edition</a></p>
                                    </div>
                                <div style="clear: both"></div><div id="j_id0:j_id1:communityFeed"><span id="j_id0:j_id1:j_id86"><script>if (!window.sfdcPage) {window.sfdcPage = new GenericSfdcPage();
UserContext.initialize({"ampm":["AM","PM"],"isAccessibleMode":false,"uiSkin":"Theme3","salesforceURL":"https://dfc-org-production.force.com?refURL=http%3A%2F%2Fdfc-org-production.force.com%2Fforums%2F","dateFormat":"M/d/yyyy","language":"en_US","locale":"en_US","userName":"salesforce_developer_community@dfc-org-production.force.com","userId":"005F0000003BGxZ","isCurrentlySysAdminSU":false,"renderMode":"RETRO","startOfWeek":"1","vfDomainPattern":"(?:[^.]+)*.na43.visual.force.com","auraDomain":"na43.lightning.force.com","dateTimeFormat":"M/d/yyyy h:mm a","orgPreferences":[{"index":257,"name":"TabOrganizer","value":true},{"index":113,"name":"GroupTasks","value":true}],"siteUrlPrefix":"/forums","isDefaultNetwork":false,"labelLastModified":"1479844900000","today":"11/26/2016 4:58 PM","timeFormat":"h:mm a","userPreferences":[{"index":112,"name":"HideInlineEditSplash","value":false},{"index":114,"name":"OverrideTaskSendNotification","value":false},{"index":115,"name":"DefaultTaskSendNotification","value":false},{"index":119,"name":"HideUserLayoutStdFieldInfo","value":false},{"index":116,"name":"HideRPPWarning","value":false},{"index":87,"name":"HideInlineSchedulingSplash","value":false},{"index":88,"name":"HideCRUCNotification","value":false},{"index":89,"name":"HideNewPLESplash","value":false},{"index":90,"name":"HideNewPLEWarnIE6","value":false},{"index":122,"name":"HideOverrideSharingMessage","value":false},{"index":91,"name":"HideProfileILEWarn","value":false},{"index":93,"name":"HideProfileElvVideo","value":false},{"index":97,"name":"ShowPicklistEditSplash","value":false},{"index":92,"name":"HideDataCategorySplash","value":false},{"index":128,"name":"ShowDealView","value":false},{"index":129,"name":"HideDealViewGuidedTour","value":false},{"index":132,"name":"HideKnowledgeFirstTimeSetupMsg","value":false},{"index":104,"name":"DefaultOffEntityPermsMsg","value":false},{"index":135,"name":"HideNewCsnSplash","value":false},{"index":101,"name":"HideBrowserWarning","value":false},{"index":139,"name":"HideDashboardBuilderGuidedTour","value":false},{"index":140,"name":"HideSchedulingGuidedTour","value":false},{"index":180,"name":"HideReportBuilderGuidedTour","value":false},{"index":183,"name":"HideAssociationQueueCallout","value":false},{"index":194,"name":"HideQTEBanner","value":false},{"index":193,"name":"HideChatterOnboardingSplash","value":false},{"index":195,"name":"HideSecondChatterOnboardingSplash","value":false},{"index":270,"name":"HideIDEGuidedTour","value":false},{"index":282,"name":"HideQueryToolGuidedTour","value":false},{"index":196,"name":"HideCSIGuidedTour","value":false},{"index":271,"name":"HideFewmetGuidedTour","value":false},{"index":272,"name":"HideEditorGuidedTour","value":false},{"index":205,"name":"HideApexTestGuidedTour","value":false},{"index":206,"name":"HideSetupProfileHeaderTour","value":false},{"index":207,"name":"HideSetupProfileObjectsAndTabsTour","value":false},{"index":213,"name":"DefaultOffArticleTypeEntityPermMsg","value":false},{"index":214,"name":"HideSelfInfluenceGetStarted","value":false},{"index":215,"name":"HideOtherInfluenceGetStarted","value":false},{"index":216,"name":"HideFeedToggleGuidedTour","value":false},{"index":268,"name":"ShowChatterTab178GuidedTour","value":false},{"index":275,"name":"HidePeopleTabDeprecationMsg","value":false},{"index":276,"name":"HideGroupTabDeprecationMsg","value":false},{"index":224,"name":"HideUnifiedSearchGuidedTour","value":false},{"index":226,"name":"ShowDevContextMenu","value":true},{"index":227,"name":"HideWhatRecommenderForActivityQueues","value":false},{"index":228,"name":"HideLiveAgentFirstTimeSetupMsg","value":false},{"index":232,"name":"HideGroupAllowsGuestsMsgOnMemberWidget","value":false},{"index":233,"name":"HideGroupAllowsGuestsMsg","value":false},{"index":234,"name":"HideWhatAreGuestsMsg","value":false},{"index":235,"name":"HideNowAllowGuestsMsg","value":false},{"index":236,"name":"HideSocialAccountsAndContactsGuidedTour","value":false},{"index":237,"name":"HideAnalyticsHomeGuidedTour","value":false},{"index":238,"name":"ShowQuickCreateGuidedTour","value":false},{"index":245,"name":"HideFilePageGuidedTour","value":false},{"index":250,"name":"HideForecastingGuidedTour","value":false},{"index":251,"name":"HideBucketFieldGuide","value":false},{"index":263,"name":"HideSmartSearchCallOut","value":false},{"index":265,"name":"HideSocialProfilesKloutSplashScreen","value":false},{"index":273,"name":"ShowForecastingQuotaAttainment","value":false},{"index":280,"name":"HideForecastingQuotaColumn","value":false},{"index":301,"name":"HideManyWhoGuidedTour","value":false},{"index":284,"name":"HideExternalSharingModelGuidedTour","value":false},{"index":298,"name":"HideFileSyncBannerMsg","value":false},{"index":299,"name":"HideTestConsoleGuidedTour","value":false},{"index":302,"name":"HideManyWhoInlineEditTip","value":false},{"index":303,"name":"HideSetupV2WelcomeMessage","value":false},{"index":312,"name":"ForecastingShowQuantity","value":false},{"index":313,"name":"HideDataImporterIntroMsg","value":false},{"index":314,"name":"HideEnvironmentHubLightbox","value":false},{"index":316,"name":"HideSetupV2GuidedTour","value":false},{"index":317,"name":"HideFileSyncMobileDownloadDialog","value":false},{"index":322,"name":"HideEnhancedProfileHelpBubble","value":false},{"index":328,"name":"ForecastingHideZeroRows","value":false},{"index":330,"name":"HideEmbeddedComponentsFeatureCallout","value":false},{"index":341,"name":"HideDedupeMatchResultCallout","value":false},{"index":340,"name":"HideS1BrowserUI","value":true},{"index":346,"name":"HideS1Banner","value":false},{"index":358,"name":"HideEmailVerificationAlert","value":false},{"index":354,"name":"HideLearningPathModal","value":false},{"index":359,"name":"HideAtMentionsHelpBubble","value":false},{"index":368,"name":"LightningExperiencePreferred","value":false}],"networkId":"0DBF0000000PAtV"});
}</script><script>chatterService.getToolbox().setIsGuestUser(true);</script><script>chatterService.getToolbox().setDataServletUrl('/forums/_ui/chatter/service/setup/ChatterServicePersonalSetup');</script><div class=" csoptimizequestion cxthefeed" id="cs:theFeed"><div><div class="cxfeedcontainer"><div class="csfeedcontainer cxSingleQuestionDetailFeed"><ul class="cxBreadcrumbs breadCrumbs"><li class="first cxBreadcrumbCriteria"><a href="#" class="cxquestionbreadcrumbbest"><span class="cxquestionbreadcrumbbest">Solved Questions</span></a></li><li class="last current"><span>This Question</span></li></ul>
<div class="cx906F00000008pc4 cxfeeditem feeditem" data-scc="{feedItemId:'906F00000008pc4IAA',ownerId:'005F0000003FfZc',communityId:'09aF00000004HMGIA2'}"><div class="feeditemcontent cxfeeditemcontent"><div class="cxquestionheader"><span class="usericon"><img src="https://dfc-org-production.force.com/img/userprofile/default_profile_45_v2.png" alt="RedSales" width="45" height="45" class="cxuserimage" title="RedSales" /></span><span class="feeditemfirstentity"><a href="https://dfc-org-production.force.com/forums/ForumsProfile?communityId=09aF00000004HMG&amp;userId=005F0000003FfZc&amp;showHeader=false">RedSales</a></span>&nbsp;<h1 class="feeditemtext feeditemheader cxnotchatterlikesiv">What does the &quot;%2F&quot; characters mean when used before an object in a URL?</h1><div class="feeditemtext cxnotchatterlikesiv"><p>Hello,</p><p> </p><p>I&#39;ve noted in Salesforce.com url&#39;s that querystring parameters often contain the characters %2F  before an object. What is the purpose of these characters &amp; what do they mean?</p><p> </p><p>An example is the following &quot;retURL=%2F01QQ1000007E4cm&quot;</p><p>Where &quot;01QQ1000007E4cm&quot; is the object id.</p><p> </p><p>Thanking you for your help.</p></div></div><ul class="feeditemfooter"><li class="feeditemtimestamp">May 10, 2011</li><li class="feeditemseparatingdot"> · </li><li class="cxlike" title="Like this"><a href="#" class="cxusefullink">Like</a></li><li class="upVoteCount" data-value="1">1</li><li class="feeditemseparatingdot"> · </li><li class="cxfollow" title="Follow this question to receive email updates"><a href="#" class="cxfollowlink">Follow</a></li><li class="followCount" data-value="0" title="0">0</li></ul>
<div class="feeditemextras"><div class="cxfeedcommentarrow feedcommentarrow"></div><div class="cxcomments feeditemcomments"><div class="cxbestReply"><div class="cx907F00000008sS3 feeditemcomment cxfeedcomment cxfeedItemBestReplyText" data-scc="{feedItemId:'907F00000008sS3IAI',ownerId:'005F0000003Ffzw'}" onblur="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onfocus="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);" onmouseout="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onmouseover="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);"><div class="feeditembestreplyheader"><img src="/forums/s.gif" alt=""  class="csFeedItemBestReplyByCustomerSupportIcon feedItemBestReplyIcon" />Best Answer chosen by Admin&nbsp;<span class="csCompanyNameTag">(Salesforce Developers)</span>&nbsp;<img src="/forums/s.gif" alt=""  class="agentIcon" /></div><div class="feeditemcommentbody"><span class="usericon"><img src="https://dfc-org-production.force.com/img/userprofile/default_profile_45_v2.png" alt="Ritesh Aswaney" width="30" height="30" class="cxuserimage" title="Ritesh Aswaney" /></span><strong class="feedText"><span class="feedcommentuser"><a href="https://dfc-org-production.force.com/forums/ForumsProfile?communityId=09aF00000004HMG&amp;userId=005F0000003Ffzw&amp;showHeader=false">Ritesh Aswaney</a></span><div class="feedcommenttext"><p>Its the URL Encoded value of the Forward Slash (/)</p><p> </p><p>Special characters need to be encoded in URL&#39;s, eg. +, &amp; , etc</p><p> </p><p><a href="http://www.blooberry.com/indexdot/html/topics/urlencoding.htm" target="_blank">http://www.blooberry.com/indexdot/html/topics/urlencoding.htm</a></p></div></strong><ul class="feeditemfooter"><li class="feeditemtimestamp">May 10, 2011</li><li class="feeditemreplysepdot1"> · </li><li class="cxlike" title="Like this"><a href="#" class="cxlikelink">Like</a></li><li class="upVoteCount" data-value="2">2</li><li class="feeditemreplysepdot2"> · </li><li class="cxdislike" title="Dislike this"><a href="#" class="cxdislikelink">Dislike</a></li><li class="downVoteCount" data-value="0">0</li></ul>
</div><div class="replyerrorcontainer" style="display:none"></div></div></div><div class="header"><h3>All Answers</h3></div><div class="cxfeedcomment csBestReplyInSIV cx907F00000008sS3 feeditemcomment" data-scc="{feedItemId:'907F00000008sS3IAI',ownerId:'005F0000003Ffzw'}" onblur="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onfocus="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);" onmouseout="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onmouseover="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);"><div class="feeditemcommentbody"><span class="usericon"><img src="https://dfc-org-production.force.com/img/userprofile/default_profile_45_v2.png" alt="Ritesh Aswaney" width="30" height="30" class="cxuserimage" title="Ritesh Aswaney" /></span><strong class="feedText"><span class="feedcommentuser"><a href="https://dfc-org-production.force.com/forums/ForumsProfile?communityId=09aF00000004HMG&amp;userId=005F0000003Ffzw&amp;showHeader=false">Ritesh Aswaney</a></span><div class="feedcommenttext"><p>Its the URL Encoded value of the Forward Slash (/)</p><p> </p><p>Special characters need to be encoded in URL&#39;s, eg. +, &amp; , etc</p><p> </p><p><a href="http://www.blooberry.com/indexdot/html/topics/urlencoding.htm" target="_blank">http://www.blooberry.com/indexdot/html/topics/urlencoding.htm</a></p></div></strong><div class="bestPlaceHolder">This was selected as the best answer</div></div><div class="replyerrorcontainer" style="display:none"></div></div><div class="cx907F000000090hU feeditemcomment cxfeedcomment" data-scc="{feedItemId:'907F000000090hUIAQ',ownerId:'005F0000003Firr'}" onblur="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onfocus="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);" onmouseout="Sfdc.Dom.removeClass(this, &#39;cxhover&#39;);" onmouseover="Sfdc.Dom.addClass(this, &#39;cxhover&#39;);"><div class="feeditemcommentbody"><span class="usericon"><img src="https://dfc-org-production.force.com/img/userprofile/default_profile_45_v2.png" alt="Jeff Bloomer" width="30" height="30" class="cxuserimage" title="Jeff Bloomer" /></span><strong class="feedText"><span class="feedcommentuser"><a href="https://dfc-org-production.force.com/forums/ForumsProfile?communityId=09aF00000004HMG&amp;userId=005F0000003Firr&amp;showHeader=false">Jeff Bloomer</a></span><div class="feedcommenttext"><p>Here&#39;s another good resource on the topic.  It has a nice, long list for convenience.</p><p> </p><p><a href="http://www.w3schools.com/tags/ref_urlencode.asp" target="_blank" title="HTML URL Encoding Reference">http://www.w3schools.com/tags/ref_urlencode.asp</a></p></div></strong><ul class="feeditemfooter"><li class="feeditemtimestamp">July 17, 2013</li><li class="feeditemreplysepdot1"> · </li><li class="cxlike" title="Like this"><a href="#" class="cxlikelink">Like</a></li><li class="upVoteCount" data-value="0">0</li><li class="feeditemreplysepdot2"> · </li><li class="cxdislike" title="Dislike this"><a href="#" class="cxdislikelink">Dislike</a></li><li class="downVoteCount" data-value="0">0</li></ul>
</div><div class="replyerrorcontainer" style="display:none"></div></div></div><div class="cxnewcomment" style="display:none">
    <div class="cxcommententry feeditemcomment feeditemcommenttext">
        <div class="feeditemcommentnew">
<textarea  class="foobar cxnewcommenttext" id="" maxlength="32001" name="" tabindex="0" title="Write an answer or comment..." type="text" wrap="soft"></textarea>            <div class="cxvalidationmessage newcommenterrorcontainer" style="display:none"></div>
            <div>
                <input class="btn cxnewcommentaction newcommentbutton cxnewpublicreply" type="button" value="Answer" title="Answer" />
            </div>
            <div class="feedclearfloat"></div>
        </div>
    </div>
</div>
<div style="display:block" class="feeditemcommentplaceholder cxcommentplaceholder">
    <input type="text" readonly="true" value="Write an answer or comment..." class="cxcommentplaceholderaction" data-isPrivateConversation="false" />
</div></div></div></div></div></div></div></div><div id="cs:inlineSignIn" class="prompt" onclick="chatterService.getLogin().clearPrompt()" style="visibility: hidden">
    <h3>You need to sign in to do that.</h3>
    <div> 
        <strong>Need an account?</strong> 
        <a href="javascript:void(0);" id="cs:inlineSignUpButton">Sign Up</a>
    </div>
    <div class="last"> 
        <strong>Have an account?</strong>
            <a href="javascript:void(0);" id="cs:inlineSignInButton">Sign In</a>
    </div> 
    <a href="javascript:void(0);" id="cs:inlineDismiss" class="dismiss">Dismiss</a>
</div><div class="cxfooter">
    <ul id="cs:footer" class="">
            <li><a href="javascript:openPopupFocusEscapePounds(%27https://dfc-org-production.force.com/forums/ChatterAnswersHelp%27, %27Help%27, 1024, 768, %27width=1024,height=768,resizable=yes,toolbar=yes,status=yes,scrollbars=yes,menubar=yes,directories=no,location=yes,dependant=no%27, false, false);">Need help?</a></li>
    </ul>
</div>
<script>Ext.fly(window).on('load', function() {if ((window.sfdcPage) && (sfdcPage.executeOnloadQueue)){sfdcPage.executeOnloadQueue();};chatterService.getToolbox().setNoSignIn('false');chatterService.getToolbox().setSitePrefix('/forums');chatterService.getToolbox().setLanguage('en_US');chatterService.getToolbox().setIsHeaderRendered(false);chatterService.getToolbox().setProfilePageUrl('https://dfc-org-production.force.com/forums/ForumsProfile');chatterService.initFeeds({reputationEnabled:true,isTBEnabled:true,isRTEnabled:true,inPortal:false,loginPageUrl:'https://dfc-org-production.force.com/forums/ChatterAnswersLogin'}, {criteria:'BESTANSWERS',dataCategory:'Developer_Forums',communityId:'09aF00000004HMGIA2',jsApiPilot:'false',riutiz:'false',pp:'https://dfc-org-production.force.com/forums/ForumsProfile',baseUrl:'https://dfc-org-production.force.com/forums/'});});</script></span></div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            
            <div aria-hidden="true" aria-labelledby="categories_modal_Label" class="modal hide fade" id="categories_modal" role="dialog" tabindex="-1">
              <div class="modal-header">
                <button aria-hidden="true" class="close" data-dismiss="modal" type="button">&times;</button>
                <h3 id="categories_modal_Label">Select a category</h3>
              </div>
              <div class="modal-body">
                <div id="categories-modal-body"></div>
              </div>
            </div><!--<dfc-footer>-->
  <footer>
        <div class="footer-top">
            <div class="container">
                <div class="row small">
                    <div class="footerCols1">
                        <h3>
Get started                     </h3>
                        <ul class="unstyled">
                            <li>
                                <a href="/platform">
Salesforce App Cloud                                </a>
                            </li>
                            <li>
                                <a href="/gettingstarted">
Force.com                               </a>
                            </li>
                            <li>
                                <a href="https://devcenter.heroku.com/start">
Heroku                              </a>
                            </li>
                        </ul>
                    </div>
                    <div class="footerCols1">
                        <h3>
Salesforce Dev Centers                      </h3>
                        <ul class="unstyled">
                            <li>
                                <a href="/devcenter/lightning">
Lightning Developer Center                              </a>
                            </li>
                            <li>
                                <a href="/devcenter/mobile">
Mobile Developer Center                             </a>
                            </li>
                            <li>
                                <a href="http://devcenter.heroku.com/">
Heroku Dev Center                               </a>
                            </li>
                            <li>
                                <a href="http://dev.desk.com/">
Desk.com &lt;/developers&gt;                                </a>
                            </li>
                            <li>
                                <a href="http://developer.pardot.com/">
Pardot Developer Site                               </a>
                            </li>
                        </ul>
                    </div>
                    <div class="footerCols1">
                        <h3>
Developer resources                     </h3>
                        <ul class="unstyled">
                            <li>
                                <a href="/mobile">
Mobile Services                             </a>
                            </li>
                            <li>
                                <a href="javascript:window.location = '/docs/?service=Force.com&amp;sort=title'">
Force.com Docs                              </a>
                            </li>
                            <li>
                                <a href="/page/Tools">
Force.com Downloads                             </a>
                            </li>
                            <li>
                                <a href="javascript:window.location = '/docs/?service=Heroku'">
Heroku Docs                             </a>
                            </li>
                            <li>
                                <a href="http://toolbelt.heroku.com/">
Heroku Downloads                                </a>
                            </li>
                            <li>
                                <a href="/trailhead?utm_campaign=trailhead&amp;utm_source=website&amp;utm_medium=dsc_footer">
Learn Salesforce with Trailhead                             </a>
                            </li>
                        </ul>
                    </div>
                    <div class="footerCols1">
                        <h3>
Community                       </h3>
                        <ul class="unstyled">
                            <li>
                                <a href="/forums">
Developer Forums                                </a>
                            </li>
                            <li>
                                <a href="/calendar">
Salesforce Developer Events                             </a>
                            </li>
                            <li>
                                <a href="/content/type/Webinar">
Webinars                                </a>
                            </li>
                        </ul>
                    </div>
                    <div class="footerCols1">
                        <h3>
Learn more                      </h3>
                        <ul class="unstyled">
                            <li>
                                <a href="/appexchange">
Salesforce AppExchange                              </a>
                            </li>
                            <li>
                                <a href="//admin.salesforce.com">
Salesforce Administrators                               </a>
                            </li>
                            <li>
                                <a href="//help.salesforce.com/">
Salesforce.com Help Portal                              </a>
                            </li>
                        </ul>
                    </div>
                </div>
                <div class="row">
                    <div class="span9">
<!--<dfc-footer-copyright>-->                       <span class="footer-copyright">
© Copyright 2000-2016 salesforce.com, inc. All rights reserved. Various trademarks held by their respective owners.<br>Salesforce.com, inc. The Landmark @ One Market, Suite 300, San Francisco, CA 94105, United States                        </span>
<!--</dfc-footer-copyright>-->                      <div class="footer-links small">
                            <a href="//www.salesforce.com/company/privacy.jsp">
Privacy Statement                           </a>
                            <a href="//www.salesforce.com/company/security.jsp">
Security Statement                          </a>
                            <a href="/files/tos/Developerforce_TOU_20101119.pdf">
Terms of Use                            </a>
                            <a class="feedback" href="#" itemid="ebd396c9-3b7c-43bd-8223-419bc8a1cbeb">
<img src="//developer.salesforce.com/resource/images/opinionlab-orange.gif" alt="Feedback">Feedback                         </a>
                            <a href="http://www.salesforce.com/company/">
About Us                            </a>
                            <a class="language-switcher" href="javascript:void(0);">
Language:                               <span class="current-language">
English                                 </span>
                            </a>
                            <div class="language-switcher-popup hidden">
                                <h4 class="language-popup-title">
Choose a Language                               </h4>
                                <ul class="unstyled language-list">
                                    <li class="active" data-language="en">
English                                 </li>
                                    <li data-language="ja">
日本語                                 </li>
                                    <li data-language="fr">
Français                                    </li>
                                    <li data-language="de">
Deutsch                                 </li>
                                </ul>
                            </div>
                        </div>
                    </div>
                    <div class="span3">
                        <ul class="social-icons unstyled">
                            <li>
                                <a href="https://www.facebook.com/salesforcedevs">
<img src="//developer.salesforce.com/resource/images/facebook.png">                             </a>
                            </li>
                            <li>
                                <a href="https://twitter.com/#!/salesforcedevs">
<img src="//developer.salesforce.com/resource/images/twitter.png">                              </a>
                            </li>
                            <li>
                                <a href="https://plus.google.com/118327959233932983591">
<img src="//developer.salesforce.com/resource/images/g.png">                                </a>
                            </li>
                            <li>
                                <a href="https://www.linkedin.com/groups/Developer-Force-Forcecom-Community-3774731">
<img src="//developer.salesforce.com/resource/images/linkedIn.png">                             </a>
                            </li>
                            <li>
                                <a href="https://www.youtube.com/user/DeveloperForce">
<img src="//developer.salesforce.com/resource/images/youTube.png">                              </a>
                            </li>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
    </footer>
<script type="text/javascript" src="//developer.salesforce.com/resource/javascripts/footerbottom.min.js"></script>
<script type="text/javascript" src="/resource/javascripts/addthisconfig.min.js"></script>
<script type="text/javascript" src="//s7.addthis.com/js/300/addthis_widget.js#pubid=ra-5329fb0d17e1f4da"></script>
<!--</dfc-footer>--><!--<dfc-metrics>-->
<script type="text/javascript">
  // Google analytics 
  var _curLocationQuery = window.location.search.toLowerCase();
  if (!(
    _curLocationQuery.indexOf("un%3d") > -1 || 
    _curLocationQuery.indexOf("pw%3d") > -1 || 
    _curLocationQuery.indexOf("un=") > -1 || 
    _curLocationQuery.indexOf("pw=") > -1
  )) {
   var dataLayer = [];
   (function(w,d,s,l,i){
    w[l]=w[l]||[];w[l].push({'gtm.start':
   new Date().getTime(),event:'gtm.js'});
    var f=d.getElementsByTagName(s)[0],
      j=d.createElement(s),
      dl=l!=='dataLayer'?'&l='+l:'';
      
    j.async=true;
    j.src='//www.googletagmanager.com/gtm.js?id='+i+dl;
    f.parentNode.insertBefore(j,f);
   })(window,document,'script','dataLayer','GTM-MWZCN8');
  }
  
  // Adroll 
  adroll_adv_id = "KHANGVX5FNHJFGIKX7U7K5";
  adroll_pix_id = "ZDMR3ICVVVCZPHFRE3X6IU";
  (function () {
  var oldonload = window.onload;
  window.onload = function(){
     __adroll_loaded=true;
     var scr = document.createElement("script");
     var host = (("https:" == document.location.protocol) ? "https://s.adroll.com" : "http://a.adroll.com");
     scr.setAttribute('async', 'true');
     scr.type = "text/javascript";
     scr.src = host + "/j/roundtrip.js";
     ((document.getElementsByTagName('head') || [null])[0] ||
      document.getElementsByTagName('script')[0].parentNode).appendChild(scr);
     if(oldonload){oldonload()}};
  }());
</script>

<!--</dfc-metrics>-->
        <script src="//res.cloudinary.com/hy4kyit2a/raw/upload/qTip2_1.js" type="text/javascript"></script>
    </body>
</html>