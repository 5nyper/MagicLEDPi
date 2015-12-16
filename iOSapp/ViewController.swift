//
//  ViewController.swift
//  MagicLEDPi
//
//  Created by Vikaton on 12/10/15.
//  Copyright © 2015 Vikaton. All rights reserved.
//

import UIKit
import Alamofire

var COLOR = ""

class ViewController: UIViewController {

    @IBOutlet weak var red: UIButton!
    @IBOutlet weak var green: UIButton!
    @IBOutlet weak var blue: UIButton!
    @IBOutlet weak var purple: UIButton!
    @IBOutlet weak var pink: UIButton!
    @IBOutlet weak var yellow: UIButton!
    @IBOutlet weak var white: UIButton!
    override func viewDidLoad() {
        super.viewDidLoad()
        red.backgroundColor = UIColor.redColor()
        green.backgroundColor = UIColor.greenColor()
        blue.backgroundColor = UIColor.blueColor()
        purple.backgroundColor = UIColor.purpleColor()
        pink.backgroundColor = UIColor.magentaColor()
        yellow.backgroundColor = UIColor.yellowColor()
        white.backgroundColor = UIColor.whiteColor()
        
        let buttons: [UIButton] = [red,green,blue,purple,pink, yellow,white]
        for x in buttons {
            x.layer.cornerRadius = 50;
        }
        Alamofire.request(.GET, "https://0.0.0.0/")
            .responseString { response in
                if response.result.value == nil {
                    let alert = UIAlertView()
                    alert.title = "No Internet Connection"
                    alert.message = "Please connect to the Internet to control the LEDs"
                    alert.addButtonWithTitle("Ok")
                    alert.show()
                }
        }
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func onTouch(sender: UIButton!) {
        if sender.backgroundColor!.isEqual(UIColor.redColor()) {
            COLOR = "RED"
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=\(COLOR)")
                .responseString { response in
                print(response.result)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.magentaColor()) {
            COLOR = "PINK"
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=\(COLOR)")
                .responseString { response in
                    print(response.result.value)
            }
        }

        else if sender.backgroundColor!.isEqual(UIColor.greenColor()) {
            COLOR = "GREEN"
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=\(COLOR)")
                .responseString { response in
                    print(response.result.value)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.blueColor()) {
            COLOR = "BLUE"
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=\(COLOR)")
                .responseString { response in
                    print(response.result.value)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.purpleColor()) {
            COLOR = "PURPLE"
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=\(COLOR)")
                .responseString { response in
                    print(response.result.value)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.whiteColor()) {
            COLOR = "WHITE"
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=\(COLOR)")
                .responseString { response in
                    print(response.result.value)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.yellowColor()) {
            COLOR = "YELLOW"
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=\(COLOR)")
                .responseString { response in
                    print(response.result.value)
            }
        }

    }

}
