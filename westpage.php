<?php
require 'LayerPage.inc';
require 'PageCreator.inc';

$page_creator = new PageCreator("page_data/westpage.xml");
$page_data = $page_creator->parse();

$page = new LayerPage($page_data);
$page->display();
?>