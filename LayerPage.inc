<?php
require 'Page.inc';
require 'Constants.inc';

class LayerPage extends Page
{
  public $page_data;

  function __construct($page_data)
  {
        parent::__construct($page_data->name());
        $this->page_data = $page_data;
  }
  
  protected function echoJS()
  {
  	?>
    <script type="text/javascript">
      var menu_item_background_color = 

      function setBackgroundColor(id, color)
      {
        if(id != undefined && color != undefined)
        {
          document.getElementById(id).style.backgroundColor = color;
        }

      }
      
      function setBackgroundPicture(picture)
      {
        if(picture != undefined)
        {
          document.getElementById('left_column').style.backgroundImage = "url('"+picture+"')";
        }
      }

      function setDefaultBackgroundPic()
      {
        <?php
          echo "setBackgroundPicture('".$this->page_data->defaultPic()."');\n";
        ?>
      }

      var activeClassname;
      function triggerLayer(classname,picture)
      {
        dismissFullScreenImg(); // In case in full screen mode
        // Main Menu Description
        if(activeClassname != undefined)
        {
          hideElementsByClassName(activeClassname);
        }
        if(activeClassname == classname) // i.e the user wants to hide all elements
        {
          activeClassname = undefined;
          setDefaultBackgroundPic();
          hideThumbnails();
          return;
        }
        showThumbnails();
        showElementsByClassName(classname);
        setBackgroundPicture(picture);
        activeClassname=classname;
      }

      function showThumbnails()
      {
        showElementById('thumbnails_root_container');
      }

      function hideThumbnails()
      {
        hideElementById('thumbnails_root_container');
      }

      function hideElementById(id)
      {
        document.getElementById(id).style.display = "none";
      }

      function showElementById(id)
      {
        document.getElementById(id).style.display = "block";
      }

      function hideElementsByClassName(classname)
      {
        var elements = document.getElementsByClassName(classname);
        if(elements.length > 0)
        {
          for (var i = 0; i < elements.length; i++) {
            var element = elements[i];
            element.style.display = "none";
          }
        }
      }
      
      function showElementsByClassName(classname)
      {
        var elements = document.getElementsByClassName(classname);
        if(elements.length > 0)
        {
          for (var i = 0; i < elements.length; i++) {
            var element = elements[i];
            element.style.display = "block";
          }
        }
      }

      function fullscreenImg(picture, description)
      {
        // hideElementById('main_page_root_container');
        document.getElementById('full_screen_subpicture').style.backgroundImage = "url('"+picture+"')";
        document.getElementById('full_screen_subpicture_desc').innerHTML=description;    
        showElementById('full_screen_subpicture_root_container');
      }

      function dismissFullScreenImg()
      {
        hideElementById('full_screen_subpicture_root_container');
        // showElementById('main_page_root_container');
      }

      function highlightMenuItem(id)
      {
        <?php
          echo "document.getElementById(id).style.backgroundColor='".Constants::MENU_ITEM_TXT_COLOR."';\n";
          echo "document.getElementById(id).style.color='".Constants::MENU_ITEM_BGD_COLOR."';\n";
        ?>
      }

      function normalizeMenuItem(id)
      {
        <?php
          echo "document.getElementById(id).style.backgroundColor='".Constants::MENU_ITEM_BGD_COLOR."';\n";
          echo "document.getElementById(id).style.color='".Constants::MENU_ITEM_TXT_COLOR."';\n";
        ?>      
      }

      function highlightPicture(id)
      {
        document.getElementById(id).style.border = "1px solid";
        document.getElementById(id).style.marginTop = "12.5px";
        document.getElementById(id).style.marginBottom = "12.5px";
        document.getElementById(id).style.height = "123px";
        document.getElementById(id).style.width = "166px";
      }

      function normalizePicture(id)
      {
        document.getElementById(id).style.border = "initial";
        document.getElementById(id).style.height = "100px";
        document.getElementById(id).style.width = "133px";
        document.getElementById(id).style.marginTop = "25px";
        document.getElementById(id).style.marginBottom = "25px";
      }

      function myEventHandler(event)
      {
        if(!event)
          event = window.event;

        //IE9 & Other Browsers
        if (event.stopPropagation) {
          event.stopPropagation();
        }
        //IE8 and Lower
        else {
          event.cancelBubble = true;
        }
      }
    </script>
    <?php
  }

  protected function echoCSS()
  {
    ?>
    <style>
    body{
      background-color: #000000;
    }
    /*LEFT COLUMN*/
    #left_column{
      float: left;
      background-size: 100% 100%;
      height: 100%;
      width: 70%;
      background-repeat: no-repeat;
      background-size: contain; 
      background-position:center;
    }
    #thumbnails_root_container{
      position: absolute;
      border-top: solid 1px;
      height: 150px;
      width: inherit;
      background-color: rgba(220,220,220,0.5);
      overflow-y: auto;
      left:0;
      right:0;
      bottom:0;
      z-index: 1;
    }
    .thumbnails_unique_layer_container{
    }
    .thumbnail{
      margin-top: 25px;
      margin-bottom: 25px;
      margin-left: 10px;
      margin-right: 10px;
      height: 100px;
      width: 133px;
    }
    #full_screen_subpicture_root_container{
      position: absolute;
      width: inherit;
      height: 100%;
      z-index: 1;
      left:0;
      right:0;
/*      <?php
      echo "background-color: ".Constants::MENU_ITEM_BGD_COLOR.";";
      ?>*/
      background-color: rgba(220,220,220,0.5);
    }
    #full_screen_subpicture_and_desc_wrapper{
      margin-top: 20px;
      border: solid 2px;
      height: 70%;
      width: 80%%;
      margin-left: auto;
      margin-right: auto;
      background-color: rgba(220,220,220,0.8);
    }
    #full_screen_subpicture{
      height: 70%;
      width: 100%;
      border-bottom: solid 1px;
      background-repeat: no-repeat;
      background-size: contain; 
      background-position:center;
      /*border: solid 2px;*/
    }
    #full_screen_subpicture_desc{
      overflow-y: auto;
      padding-top: 20px;
      font-weight:bold;
    }
    /*RIGHT COLUMN*/
    #right_column{
      float: right;
      height: 100%;
      width: 29.8%;
      <?php
      echo "border-left: solid 1px ".Constants::MENU_ITEM_BGD_COLOR.";";
      ?>
    }
    #menu_title{
      <?php
      echo "color: ".Constants::MENU_ITEM_BGD_COLOR.";";
      ?>      
      text-align: center;
      margin-left: auto;
      margin-right: auto;
    }
    .menu_item_container{
      width: 100%;
      height: 50px;
      /*vertical-align: middle;*/
      <?php
      echo "background-color: ".Constants::MENU_ITEM_BGD_COLOR.";";
      echo "color: ".Constants::MENU_ITEM_TXT_COLOR.";";
      ?>
      font-family: 'Arial Black';
    }
    .menu_item{
      text-decoration:none;
      font-size: 20px;
      /*top: 10px;*/
    }
    .layer_description{
      color: white;
      margin-top: 10px;
      margin-left: 10px;
    }
    /*MISC*/
    .pointer_on_hover
    {
      cursor: pointer;
    }
    </style>
    <?php
  }

  
  protected function echoBody()
  {
  	?>
  	<body onload="setDefaultBackgroundPic()">
      <!-- LEFT COLUMN -->
  		<div id="left_column">
        <div id='full_screen_subpicture_root_container' onclick='dismissFullScreenImg()' style="display: none;">
          <div id='full_screen_subpicture_and_desc_wrapper' onclick='myEventHandler(event)'>
              <div id='full_screen_subpicture'> </div>
              <div id='full_screen_subpicture_desc'> </div>
          </div>
        </div>
      <div id='thumbnails_root_container' style="display: none;">
<?php
foreach ($this->page_data->layers() as $layer) {
        echo "<div class='thumbnails_unique_layer_container ".$layer->id()."' style=\"display: none;\">";
foreach ($layer->thumbnails() as $thumbnail) {
          echo "<img id='".$thumbnail->picture()."' class='thumbnail pointer_on_hover' src='".$thumbnail->picture()."' onmouseover='highlightPicture(\"".$thumbnail->picture()."\")'  onmouseout='normalizePicture(\"".$thumbnail->picture()."\")' onclick=\"fullscreenImg('".$thumbnail->fullscreen_picture()."','".$thumbnail->description()."')\"/>";
 }
        echo "</div>"; //sub_picture_layer_container
 }
?>
      </div>
    </div>

    <div id='right_column'>
<?php
    echo "<h1 id='menu_title'>".$this->page_data->name()."</h1>";
foreach ($this->page_data->layers() as $layer) {
$menu_item_container_id = $this->getMenuItemContainerId($layer->id());
      echo "<div id='".$menu_item_container_id."' class='menu_item_container pointer_on_hover' onclick=\"triggerLayer('".$layer->id()."','".$layer->picture()."')\" onmouseout='normalizeMenuItem(\"".$menu_item_container_id."\")' onmouseover='highlightMenuItem(\"".$menu_item_container_id."\")'>";
        echo "<span class='menu_item'>".$layer->name()." </span> <br/>";
      echo "</div>";
      echo "<div class='layer_description ".$layer->id()."' style=\"display: none;\">".$layer->description()."</div> <br/>";
}
?>
    </div>
	 </body> 	
<?php
}

  protected function getMenuItemContainerId($id)
  {
    return "menuitemcontainer_".$id;
  }
}